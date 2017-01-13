/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cMeanModel.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 4:07 PM
 */

#ifndef CMEANMODEL_H
#define CMEANMODEL_H

#include "cData.h"
#include "cGradient.h"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;

class cMeanModel {
public:
    
    cGSLVector *mParams;
    cMeanModel();
    cMeanModel(const cGSLVector& theParam);
    cMeanModel(const cMeanModel& orig);
    cData& operator = (const cData & theData);
    int mGetSize();
    virtual double mComputeMean(const cData& theData, int theNbCompute) const = 0; //passage par copie => ajouter référence pour ne pas recopier
    virtual cGSLVector* mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad) = 0;
    virtual cMeanModel* ptrCopy() const = 0;
    virtual ~cMeanModel();
private:

};

#endif /* CMEANMODEL_H */

