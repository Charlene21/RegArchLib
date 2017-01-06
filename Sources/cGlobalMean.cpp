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
    // Version Provisoire pour tester nos fonctions
    cGSLVector const *myVect = new cGSLVector(1,6);
    cAR * myAR = new cAR(*myVect);
    cGSLVector const *myVect2 = new cGSLVector(1,7);
    cMA * myMA = new cMA(*myVect2);
    
    this->mMean.push_back(myAR);
    this->mMean.push_back(myMA);
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