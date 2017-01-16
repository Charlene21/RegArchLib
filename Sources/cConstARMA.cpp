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

cConstARMA::cConstARMA(const cGSLVector& theParam) : cMeanModel(theParam) {
    
}

cConstARMA::cConstARMA(const cConstARMA& orig) : cMeanModel(orig) {
    
}

double cConstARMA::mComputeMean(const cData& theData, int theNbCompute) const {
    return (*(this->mParams))[0];
}

cGSLVector* cConstARMA::mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) {
    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    (*myPartialGrad)[theBeginIndex] = 1;
    
    return myPartialGrad;
}

cMeanModel* cConstARMA::ptrCopy() const{
    return new cConstARMA(*this);
}

cConstARMA::~cConstARMA() {
}

void cConstARMA::VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex)
	{
		uint mySize = theSrcVect.GetSize() ;
		if (this->mParams->GetSize() + theIndex > mySize)
			throw cError("Wrong size") ;
                for (int i = theIndex; i< theSrcVect.GetSize(); i++){
                    (*mParams)[i] = theSrcVect[i];
                }
             
	}