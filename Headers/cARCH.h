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

class cARCH : public cMeanModel {
public:
    cARCH();
    cARCH(const cARCH& orig);
    virtual ~cARCH();
    double mComputeMean(const cData& theData, int theNbCompute) const;
    cMeanModel* ptrCopy() const;
private:

};

#endif /* CARCH_H */

