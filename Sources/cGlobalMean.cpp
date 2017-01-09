/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGlobalMean.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 3:54 PM
 */

#include "cGlobalMean.h"
#include "cAR.h"
#include "cMA.h"

cGlobalMean::cGlobalMean() : mMean() {
    
    
    
}

void cGlobalMean :: addMean (cMeanModel *theModel){
    mMean.push_back(theModel->ptrCopy());
}

int cGlobalMean :: sizeMean () const{
    return mMean.size();
}

cGlobalMean::cGlobalMean(const cGlobalMean& orig) {
}

cGlobalMean::~cGlobalMean() {
}

double cGlobalMean::mComputeMean(const cData& theData, int theNbCompute) const {
    double myMean = 0;
    for (std::list<cMeanModel*>::const_iterator myIt = mMean.begin(); myIt != mMean.end(); ++myIt) {
        myMean += (*myIt)->mComputeMean(theData, theNbCompute);
    }
    /* ATTENTION 
     Ne pas oublier de rajouter la constante et l'autre facteur !!!!
     */
    return myMean;
}