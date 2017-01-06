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

#include "cAR.h"
#include <cstdlib>

cAR::cAR(){
 
}

cAR::cAR(const cGSLVector& theParam) : cMeanModel(theParam){
 
}

cAR::cAR(const cAR& orig) : cMeanModel(orig){
}

cAR::~cAR() {
}

double cAR:: mComputeMean(const cData& theData, int theNbCompute) const{
    double res = 0;
    for (int i = 0; i< mParams->GetSize(); i++){
        res += (*mParams)[i]*theData.mYt->operator [](theNbCompute-(i+1)); 
    }
    return res;
}

cMeanModel* cAR::ptrCopy() const{
    return new cAR(*this); 
}

