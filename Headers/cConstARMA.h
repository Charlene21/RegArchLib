/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cConstARMA.h
 * Author: paviotch
 *
 * Created on January 10, 2017, 11:12 AM
 */

#ifndef CCONSTARMA_H
#define CCONSTARMA_H

#include "cMeanModel.h"

class cConstARMA : public cMeanModel {
public:
    cConstARMA();
    cConstARMA(const cGSLVector& theParam);
    cConstARMA(const cConstARMA& orig);
    
    virtual double mComputeMean(const cData& theData, int theNbCompute) const;
    virtual cGSLVector* mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad);

    virtual cMeanModel* ptrCopy() const;
    void VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex);
    
    virtual ~cConstARMA();
private:

};

#endif /* CCONSTARMA_H */

