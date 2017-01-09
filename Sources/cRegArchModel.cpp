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
        (*(theData->mHt))[i] = mGlobalVar.mComputeVar(*theData,i);
        double myMean = mGlobalMean.mComputeMean(*theData,i); //myMean := Yt - Ut
        (*(theData->mUt))[i] = myMean + (*(theData->mYt))[i]; 
        (*(theData->mEt))[i] = (*(theData->mUt))[i] / sqrt((*(theData->mHt))[i]);
        
        myLogLikelihood += -(1/2)*log((*(theData->mHt))[i])
                            + mResiduals->mDensite((*(theData->mEt))[i],true);
    }
}

void cRegArchModel::mSimulate(cData& theData, int t) {
    theData.mYt->ReAlloc(t, 0);
    theData.mMt->ReAlloc(t, 0);
    theData.mHt->ReAlloc(t, 0);
    theData.mUt->ReAlloc(t, 0);
    theData.mEt->ReAlloc(t, 0);
    
    theData.mEt = mResiduals->mSimul(t);
    for (int i = 0; i < t; i++) {
        theData.mMt = mGlobalMean->mComputeMean(theData, t);
        theData.mHt = mGlobalVar->mComputeVar(theData, t);
        theData.mYt = theData.mMt[t] + sqrt(theData.mHt[t]) * theData.mEt[t];
        theData.mUt = theData.mYt[t] - theData.mMt[t];
    }
}