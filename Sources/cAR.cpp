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
        if (theNbCompute-i-1 >= 0)
            res += (*mParams)[i]* (*(theData.mYt))[theNbCompute-(i+1)];
    }
    return res;
}

cMeanModel* cAR::ptrCopy() const{
    return new cAR(*this); 
}

cGSLVector* cAR::mGradient(const cData& theData, int theGradSize, int theNbCompute) {
    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    //coordonnées pour les AR : de 1 à 1+nbAR
    for (int i=1; i<this->mGetSize()+1; i++) {
        //Yt-i pour ARi
        if (theNbCompute-i-1 >= 0)
            (*myPartialGrad)[i] = (*(theData.mYt))[theNbCompute-i-1];
    }
}

