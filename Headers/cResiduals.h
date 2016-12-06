/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cResiduals.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 3:57 PM
 */

#ifndef CRESIDUALS_H
#define CRESIDUALS_H
#include "StdAfxVectorAndMatrix.h"
#include "cData.h"
using namespace VectorAndMatrixNameSpace;

class cResiduals {
public:
    cGSLVector mParams;
    cResiduals();
    cResiduals(const cResiduals& orig);
    cGSLVector mSimul(int);
    double mDensite(double, bool log);
    void mGradient(cData &data, cGSLVector &vect);
    virtual ~cResiduals();
private:

};

#endif /* CRESIDUALS_H */

