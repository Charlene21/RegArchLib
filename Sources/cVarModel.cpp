/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cVarModel.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 4:23 PM
 */

#include "cVarModel.h"

cVarModel::cVarModel() {
}

cVarModel::cVarModel(const cGSLVector& theParam) {
    mParams = new cGSLVector(theParam);
}

cVarModel::cVarModel(const cVarModel& orig) {
    mParams = new cGSLVector(*(orig.mParams));
}

double cVarModel:: mGetSize(){
    return this->mParams->GetSize();
}

cData& cVarModel::operator = (const cData & theData){
    
}

cVarModel::~cVarModel() {
}

void cVarModel::VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex)
	{
		uint mySize = theSrcVect.GetSize() ;
		if (this->mParams->GetSize() + theIndex > mySize)
			throw cError("Wrong size") ;
		for (int i = theIndex; i< theSrcVect.GetSize(); i++){
                    (*mParams)[i] = theSrcVect[i];
                }
             
	}

