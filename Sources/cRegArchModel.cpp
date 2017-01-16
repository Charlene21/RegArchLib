/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cRegArchModel.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 3:51 PM
 */

#include <cmath>

#include "cRegArchModel.h"
#include "cNormResiduals.h"

cRegArchModel::cRegArchModel() {
    this->mGlobalMean = new cGlobalMean();
    this->mGlobalVar = new cGlobalVar();
    this->mResiduals = new cNormResiduals();
}

cRegArchModel::cRegArchModel(const cRegArchModel& orig) {
}

cRegArchModel::~cRegArchModel() {
}

double cRegArchModel::mLogLikelihood(cData *theData){
    double myLogLikelihood = 0;
    
    for (int i=0; i<theData->mYt->GetSize(); i++) {
        (*(theData->mHt))[i] = mGlobalVar->mComputeVar(*theData,i);
        (*(theData->mMt))[i] = mGlobalMean->mComputeMean(*theData,i); //myMean := Yt - Ut
        (*(theData->mUt))[i] = (*(theData->mYt))[i] - (*(theData->mMt))[i]; 
        (*(theData->mEt))[i] = (*(theData->mUt))[i] / sqrt((*(theData->mHt))[i]);
        
        double tmp = (*(theData->mEt))[i];
        double density = mResiduals->mDensite(tmp,true);
        myLogLikelihood += -(0.5)*log((*(theData->mHt))[i])  + density;
    }
    return myLogLikelihood;
}

void cRegArchModel::mSimulate(cData& theData, int t) {
    theData.mYt->ReAlloc(t, 0.);
    theData.mMt->ReAlloc(t, 0.);
    theData.mHt->ReAlloc(t, 0.);
    theData.mUt->ReAlloc(t, 0.);
    theData.mEt->ReAlloc(t, 0.);
    
    //Update Et
    mResiduals->mSimul(&theData,t);
    for (int i = 0; i < t; i++) {
        theData.mMt[t] = mGlobalMean->mComputeMean(theData, t);
        theData.mHt[t] = mGlobalVar->mComputeVar(theData, t);
        theData.mYt[t] = (*theData.mMt)[t] + sqrt((*theData.mHt)[t]) * (*theData.mEt)[t];
        theData.mUt[t] = (*theData.mYt)[t] - (*theData.mMt)[t];
    }
}

void cRegArchModel:: reconstruction(cData *theData){
    for (int i=0; i<theData->mYt->GetSize(); i++) {
        (*(theData->mHt))[i] = mGlobalVar->mComputeVar(*theData,i);
        double tmp = mGlobalMean->mComputeMean(*theData,i); //myMean := Yt - Ut
        (*(theData->mMt))[i] =tmp;
        (*(theData->mUt))[i] = (*(theData->mYt))[i] - (*(theData->mMt))[i]; 
        (*(theData->mEt))[i] = (*(theData->mUt))[i] / sqrt((*(theData->mHt))[i]);
    
    }
}

cGSLVector * cRegArchModel::mComputeGradient(cData &theData, int t, cGradient * theGrad){
    const cGradient *myGradPrec = new cGradient(*theGrad);
    this->reconstruction(&theData);
    double mySigma = sqrt((*theData.mHt)[t]);
    double myE = ((*theData.mYt)[t] - (*theData.mMt)[t]) / mySigma;
    
    cGSLVector* myGradMean = this->mGlobalMean->mComputeGradient(t, theData, theGrad);
    cGSLVector* myGradVar = this->mGlobalVar->mComputeGradient(t, theData, theGrad);
    
    theGrad->mGradientMean->ReAlloc(myGradPrec->mGradientMean->GetNRow(),myGradPrec->mGradientMean->GetNCol()+1,0);
    theGrad->mGradientVar->ReAlloc(myGradPrec->mGradientMean->GetNRow(),myGradPrec->mGradientMean->GetNCol()+1,0);

    for (int i = 0; i < theGrad->mGradientMean->GetNRow(); i++)
    {
        for (int j = 0; j < theGrad->mGradientMean->GetNCol(); j++){
            
            if (j==theGrad->mGradientMean->GetNCol()-1){
                 (*theGrad->mGradientMean)[i][j] = (*myGradMean)[i];
                 (*theGrad->mGradientVar)[i][j] = (*myGradVar)[i];
            }
               
            else{
                 (*theGrad->mGradientMean)[i][j] = (*myGradPrec->mGradientMean)[i][j] ;
                 (*theGrad->mGradientVar)[i][j] = (*myGradPrec->mGradientVar)[i][j] ;
            }
  
        }
    }
    
    cGSLVector * myGradE = new cGSLVector(-1/mySigma * ((*myGradMean) + (myE/mySigma) * (*myGradVar)/(2*mySigma)));
   
    cGSLVector *myGradLt = new cGSLVector(-1/mySigma * (*myGradVar)/(2*mySigma) - myE * (*myGradE));
    return myGradLt;
    
}

 cGSLVector* cRegArchModel:: mGradVraisemblance(cData &theData, int nbDates){

     int theSizeMean = mGlobalMean->sizeMean();
     int theSizeVar = mGlobalVar->mSizeVar();
     cGradient * grad = new cGradient(theSizeMean, theSizeVar, 0);
     cGSLVector *vect = new cGSLVector(theSizeMean + theSizeVar);
     for (int i = 0; i<nbDates; i++){
         vect = mComputeGradient(theData, i, grad);
     }
     return vect;
 }
 
 void cRegArchModel::RegArchParamToVector(cGSLVector& theDestVect) const{
    theDestVect.ReAlloc(mGlobalMean->sizeMean()+mGlobalVar->mSizeVar());
    int count =0;
    for (std::list<cMeanModel*>::const_iterator myIt = mGlobalMean->mMean.begin(); myIt != mGlobalMean->mMean.end(); ++myIt) {
         for (int i = 0; i<(*myIt)->mParams->GetSize(); i++){
            theDestVect[count] = (*(*myIt)->mParams)[i];
            count++;
         }
    }
    
    for (std::list<cVarModel*>::const_iterator myIt = mGlobalVar->mVar.begin(); myIt != mGlobalVar->mVar.end(); ++myIt) {
         for (int i = 0; i<(*myIt)->mParams->GetSize(); i++){
            theDestVect[count] = (*(*myIt)->mParams)[i];
            count++;
         }
    }
 }
 
 
 void cRegArchModel::VectorToRegArchParam(const cGSLVector& theSrcParam)
    {
    uint myIndex = 0 ;
    	if (mGlobalMean != NULL)
    	{	mGlobalMean->VectorToRegArchParam(theSrcParam, myIndex) ;
    		myIndex += mGlobalMean->sizeMean() ;
    	}
    	mGlobalVar->VectorToRegArchParam(theSrcParam, myIndex) ;
    	myIndex += mGlobalVar->mSizeVar();
    	//mResids->VectorToRegArchParam(theSrcParam, myIndex) ;
    
    
    }
 
 cGSLVector* cRegArchModel:: mComputeGradNumeric(double h, cData &theData){
     cGSLVector * grad = new cGSLVector(mGlobalMean->sizeMean()+mGlobalVar->mSizeVar());
     cGSLVector * theDestVect = new cGSLVector(mGlobalMean->sizeMean()+mGlobalVar->mSizeVar());
     RegArchParamToVector(*theDestVect); 
     double mllDep = mLogLikelihood(&theData);
     
     for (int i = 0; i < mGlobalMean->sizeMean()+mGlobalVar->mSizeVar(); i++){
         RegArchParamToVector(*theDestVect); 
         cout << "vect(" << i << ") : " << (*theDestVect)[i] << endl;
         cout << "vect(" << i << ") : " << theDestVect[i] << endl;
         (*theDestVect)[i] -= h;
         cout << "vect(" << i << ") : " << (*theDestVect)[i] << endl;
         cout << "vect(" << i << ") : " << theDestVect[i] << endl;
         VectorToRegArchParam(*theDestVect);
         double mllFin = mLogLikelihood(&theData);
         grad[i] = (mllDep - mllFin)/h;
         (*theDestVect)[i] += h;
         cout << "vect(" << i << ") : " << (*theDestVect)[i] << endl;
         cout << "vect(" << i << ") : " << theDestVect[i] << endl;
         VectorToRegArchParam(*theDestVect);
             
     }
     return grad;
 }