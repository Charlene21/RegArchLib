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
        if (theNbCompute-i-1 >= 0)
            res += (*mParams)[i]* (*(theData.mHt))[theNbCompute-(i+1)]; 
    }
    return res;
}

cGSLVector* cGARCH::mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) {

    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    //coordonnées pour les MA : de nbAR+1 à nbAR+1+nbMA
    for (int i=theBeginIndex; i<this->mGetSize()+theBeginIndex; i++) {
        //Yt-i pour ARi
        if (theNbCompute-i-1- theBeginIndex >= 0)
            (*myPartialGrad)[i] = (*(theData.mHt))[theNbCompute-i-1- theBeginIndex];
    }
    
    for (int i=0; i<theGradSize; i++) {
        for (int k=0; k<this->mGetSize(); k++) {
            (*myPartialGrad)[i] += (*(this->mParams))[k] * (*(thePrecGrad.mGradientVar))[i][theNbCompute-k-1];
        }
    }
    return myPartialGrad;
}


cVarModel* cGARCH::ptrCopy() const {
    return new cGARCH(*this);
}

cGARCH::~cGARCH() {
}

void cGARCH::VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex)
	{
		uint mySize = theSrcVect.GetSize() ;
		if (this->mParams->GetSize() + theIndex > mySize)
			throw cError("Wrong size") ;
                for (int i = theIndex; i< theSrcVect.GetSize(); i++){
                    (*mParams)[i] = theSrcVect[i];
                }
             
	}