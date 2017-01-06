/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGARCH.cpp
 * Author: paviotch
 * 
 * Created on December 6, 2016, 10:13 AM
 */

#include "cGARCH.h"

cGARCH::cGARCH() {
}

cGARCH::cGARCH(const cGARCH& orig) : cVarModel(orig) {
}

cGARCH::cGARCH(const cGSLVector& theParam) : cVarModel(theParam) {
 
}

double cGARCH::mComputeVar(const cData& theData, int theNbCompute) const {
    double res = 0;
    for (int i = 0; i< mParams->GetSize(); i++){
        res += (*mParams)[i]* theData.mHt->operator [](theNbCompute-(i+1)); 
    }
    return res;
}

cVarModel* cGARCH::ptrCopy() const {
    return new cGARCH(*this);
}

cGARCH::~cGARCH() {
}

