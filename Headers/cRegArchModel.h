/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cRegArchModel.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 3:51 PM
 */

#ifndef CREGARCHMODEL_H
#define CREGARCHMODEL_H
#include "cGlobalMean.h"
#include "cGlobalVar.h"
#include "cResiduals.h"
#include "cData.h"

class cRegArchModel {
public:
    
    cGlobalMean *mGlobalMean;
    cGlobalVar *mGlobalVar;
    cResiduals *mResiduals;
    
    cRegArchModel();
    cRegArchModel(const cRegArchModel& orig); 
    
    double mLogLikelihood(cData *theData);
    void reconstruction(cData *theData);
    void mSimulate(cData &data, int t);
    cGSLVector * mComputeGradient(cData &theData, int t, cGradient * theGrad);
    cGSLVector* mGradVraisemblance(cData &theData, int nbDates);
    void RegArchParamToVector(cGSLVector& theDestVect) const;
    void VectorToRegArchParam(const cGSLVector& theSrcParam);
    cGSLVector* mComputeGradNumeric(double h, cData &theData);
    virtual ~cRegArchModel();
private:

};

#endif /* CREGARCHMODEL_H */

