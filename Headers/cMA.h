/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cAR.h
 * Author: paviotch
 *
 * Created on December 6, 2016, 10:13 AM
 */

#ifndef CMA_H
#define CMA_H

#include "cMeanModel.h"

class cMA : public cMeanModel {
public:
    cMA();
    cMA(const cGSLVector& theParam);
    cMA(const cMA& orig);
    virtual ~cMA();
    double mComputeMean(const cData& theData, int theNbCompute) const;
    virtual cGSLVector* mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad);
    cMeanModel* ptrCopy() const;
private:

};

#endif /* CMA_H */

