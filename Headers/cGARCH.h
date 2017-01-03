/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGARCH.h
 * Author: paviotch
 *
 * Created on December 6, 2016, 10:13 AM
 */

#ifndef CGARCH_H
#define CGARCH_H

#include "cMeanModel.h"
#include "cVarModel.h"

class cGARCH : public cVarModel {
public:
    cGARCH();
    cGARCH(const cGSLVector& theParam);
    cGARCH(const cGARCH& orig);
    virtual double mComputeVar(const cData& theData, int theNbCompute) const;
    virtual cVarModel* ptrCopy() const;
    virtual ~cGARCH();
private:

};

#endif /* CGARCH_H */

