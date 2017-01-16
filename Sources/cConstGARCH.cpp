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

cConstGARCH::cConstGARCH(const cGSLVector& theParam) : cVarModel(theParam) {
    
}
cConstGARCH::cConstGARCH(const cConstGARCH& orig) : cVarModel(orig){
}
double cConstGARCH::mComputeVar(const cData& theData, int theNbCompute) const {
    return (*(this->mParams))[0];
}

cGSLVector* cConstGARCH::mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) {
    cGSLVector *myPartialGrad = new cGSLVector(theGradSize);
    
    (*myPartialGrad)[theBeginIndex] = 1;
    return myPartialGrad;
}

cVarModel* cConstGARCH::ptrCopy() const{
     return new cConstGARCH(*this);
}

cConstGARCH::~cConstGARCH() {
}

void cConstGARCH::VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex)
	{
		uint mySize = theSrcVect.GetSize() ;
		if (this->mParams->GetSize() + theIndex > mySize)
			throw cError("Wrong size") ;
                for (int i = theIndex; i< theSrcVect.GetSize(); i++){
                    (*mParams)[i] = theSrcVect[i];
                }
             
	}