/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cConstARMA.cpp
 * Author: paviotch
 * 
 * Created on January 10, 2017, 11:12 AM
 */

#include "cConstARMA.h"

cConstARMA::cConstARMA() {
}

cConstARMA::cConstARMA(const cConstARMA& orig) {
}

double cConstARMA::mComputeMean(const cData& theData, int theNbCompute) const {
    return (*(this->mParams))[0];
}

cGSLVector* cConstARMA::mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) {
    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    (*myPartialGrad)[theBeginIndex] = 1;
}

cConstARMA::~cConstARMA() {
}

