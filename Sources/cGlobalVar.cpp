/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGlobalVar.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 3:58 PM
 */

#include "cGlobalVar.h"

cGlobalVar::cGlobalVar() : mVar() {
}

cGlobalVar::cGlobalVar(const cGlobalVar& orig) {
}

cGlobalVar::~cGlobalVar() {
}

double cGlobalVar::mComputeVar(const cData& theData, int theNbCompute) const {
    double myVar = 0;
    for (list<cVarModel*>::const_iterator myIt = mVar.begin(); myIt != mVar.end(); myIt++) {
        myVar += (*myIt)->mComputeVar(theData, theNbCompute);
    }
    /* ATTENTION 
     Ne pas oublier de rajouter la constante et l'autre facteur !!!!
     */
    return myVar;
}

void cGlobalVar::mAddVar(cVarModel *theModel){
    mVar.push_back(theModel->ptrCopy());
}

int cGlobalVar::mSizeVar() const {
    return mVar.size();
}

cGSLVector* cGlobalVar::mComputeGradient(int theNbCompute, const cData &theData, cGradient *theGrad){
    cGSLVector *myCumulGrad = new cGSLVector(theGrad->mGradientVar->GetNRow());
    cGSLVector *myVarGrad = new cGSLVector(theGrad->mGradientVar->GetNRow());
    int myBeginIndex = 0;
    for (std::list<cVarModel*>::const_iterator myIt = mVar.begin(); myIt != mVar.end(); ++myIt) {
        myVarGrad = (*myIt)->mGradient(theData,theGrad->mGradientVar->GetNRow(),theNbCompute,myBeginIndex,*theGrad);
        *myCumulGrad += *myVarGrad;
        myBeginIndex += (*myIt)->mGetSize();
    }
    return myCumulGrad;
}