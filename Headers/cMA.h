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
    cMA(const cMA& orig);
    virtual ~cMA();
    double mComputeMean(const cData& theData, int theNbCompute) const;
    cMeanModel* ptrCopy() const;
private:

};

#endif /* CMA_H */

