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

#ifndef CAR_H
#define CAR_H

#include "cMeanModel.h"

class cAR : public cMeanModel {
public:
    cAR();
    cAR(const cGSLVector& theParam);
    cAR(const cAR& orig);
    virtual double mComputeMean(const cData& theData, int theNbCompute) const;
    virtual cMeanModel* ptrCopy() const;
    virtual ~cAR();
private:

};

#endif /* CAR_H */

