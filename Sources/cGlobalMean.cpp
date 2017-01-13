/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGlobalMean.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 3:54 PM
 */

#include "cGlobalMean.h"


cGlobalMean::cGlobalMean() : mMean() {
      
}

void cGlobalMean :: addMean (cMeanModel *theModel){
    mMean.push_back(theModel->ptrCopy());
}

int cGlobalMean :: sizeMean () const{
    return mMean.size();
}

cGlobalMean::cGlobalMean(const cGlobalMean& orig) {
}

cGlobalMean::~cGlobalMean() {
}

double cGlobalMean::mComputeMean(const cData& theData, int theNbCompute) const {
    double myMean = 0;
    for (std::list<cMeanModel*>::const_iterator myIt = mMean.begin(); myIt != mMean.end(); ++myIt) {
        myMean += (*myIt)->mComputeMean(theData, theNbCompute);
    }

    return myMean;
}

//Précondition : les cMeanModels sont rangés dans le bon ordre : cARMA - CAR - CMA (meme ordre que le gradient)
cGSLVector* cGlobalMean::mComputeGradient(int theNbCompute, const cData &theData, cGradient *theGrad) {
    cGSLVector *myCumulGrad = new cGSLVector(theGrad->mGradientMean->GetNRow());
    cGSLVector *myMeanGrad = new cGSLVector(theGrad->mGradientMean->GetNRow());
    int myBeginIndex = 0;
    for (std::list<cMeanModel*>::const_iterator myIt = mMean.begin(); myIt != mMean.end(); ++myIt) {
        myMeanGrad = (*myIt)->mGradient(theData,theGrad->mGradientMean->GetNRow(),theNbCompute,myBeginIndex,*theGrad);
        *myCumulGrad += *myMeanGrad;
        myBeginIndex += (*myIt)->mGetSize();
    }
    return myCumulGrad;
}