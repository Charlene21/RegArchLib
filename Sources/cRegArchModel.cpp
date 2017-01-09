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

#include "cRegArchModel.h"

cRegArchModel::cRegArchModel() {
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

