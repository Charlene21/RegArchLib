/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cARCH.h
 * Author: paviotch
 *
 * Created on December 6, 2016, 10:13 AM
 */

#ifndef CARCH_H
#define CARCH_H

#include "cMeanModel.h"
#include "cVarModel.h"

class cARCH : public cVarModel {
public:
    cARCH();
    cARCH(const cGSLVector& theParam);
    cARCH(const cARCH& orig);
    virtual ~cARCH();
    double mComputeVar(const cData& theData, int theNbCompute) const;
    cVarModel* ptrCopy() const;
private:

};

#endif /* CARCH_H */

