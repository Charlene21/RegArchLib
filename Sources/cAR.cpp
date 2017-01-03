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

cAR::cAR(const cAR& orig) {
}

cAR::~cAR() {
}

double cAR:: mComputeMean(const cData& theData, int theNbCompute) const{
    return 0;
}

cMeanModel* cAR::ptrCopy() const{
    return NULL;
}

