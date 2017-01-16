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

cRegArchModel::cRegArchModel() {
    this->mGlobalMean = new cGlobalMean();
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
        
        myLogLikelihood += -(0.5)*log((*(theData->mHt))[i])
                            + mResiduals->mDensite((*(theData->mEt))[i],true);
    }
}

void cRegArchModel::mSimulate(cData& theData, int t) {
    theData.mYt->ReAlloc(t, 0.);
    theData.mMt->ReAlloc(t, 0.);
    theData.mHt->ReAlloc(t, 0.);
    theData.mUt->ReAlloc(t, 0.);
    theData.mEt->ReAlloc(t, 0.);
    
    theData.mEt = mResiduals->mSimul(t);
    for (int i = 0; i < t; i++) {
        theData.mMt[t] = mGlobalMean->mComputeMean(theData, t);
        theData.mHt[t] = mGlobalVar->mComputeVar(theData, t);
        theData.mYt[t] = (*theData.mMt)[t] + sqrt((*theData.mHt)[t]) * (*theData.mEt)[t];
        theData.mUt[t] = (*theData.mYt)[t] - (*theData.mMt)[t];
    }
}

cGSLVector* cRegArchModel::mComputeGradient(cData &theData, int t, cGradient * theGrad){
    const cGradient *myGradPrec = new cGradient(theGrad);
    this->mSimulate(theData,t);
    double mySigma = sqrt(theData.mHt[t]);
    double myE = (theData.mYt[t] - theData.mMt[t]) / mySigma;
    cGSLVector* myGradMean = this->mGlobalMean->mComputeGradient(t, theData, theGrad);
    cGSLVector* myGradVar = this->mGlobalVar->mComputeGradient(t, theData, theGrad);
    //theGrad->mGradientMean->ReAlloc(myGradPrec->mGradientMean->GetNRow(),myGradPrec->mGradientMean->GetNCol()+1,0);

    //theGrad->mGradientMean[i];
}