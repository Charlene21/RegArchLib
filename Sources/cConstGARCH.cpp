/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cConstGARCH.cpp
 * Author: paviotch
 * 
 * Created on January 10, 2017, 11:12 AM
 */

#include "cConstGARCH.h"

cConstGARCH::cConstGARCH() {
}

cConstGARCH::cConstGARCH(const cConstGARCH& orig) {
}
double cConstGARCH::mComputeVar(const cData& theData, int theNbCompute) const {
    return (*(this->mParams))[0];
}

cGSLVector* cConstGARCH::mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) {
    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    (*myPartialGrad)[theBeginIndex] = 1;
}

cVarModel* cConstGARCH::ptrCopy() const{
    
}

cConstGARCH::~cConstGARCH() {
}

