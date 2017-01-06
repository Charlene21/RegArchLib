/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cAR.cpp
 * Author: paviotch
 * 
 * Created on December 6, 2016, 10:13 AM
 */

#include "cMA.h"

cMA::cMA() {
}

cMA::cMA(const cMA& orig) : cMeanModel(orig) {
}

cMA::~cMA() {
}

double cMA:: mComputeMean(const cData& theData, int theNbCompute) const{
    double res = 0;
    for (int i = 0; i< mParams->GetSize(); i++){
        res += (*mParams)[i]* theData.mUt->operator [](theNbCompute-(i+1)); 
    }
    return res;
}

cMeanModel* cMA::ptrCopy() const{
    return new cMA(*this);
}

