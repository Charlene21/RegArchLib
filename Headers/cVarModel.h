/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cVarModel.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 4:23 PM
 */

#ifndef CVARMODEL_H
#define CVARMODEL_H

#include "cData.h"
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;

class cVarModel {
public:
    cGSLVector *mParams;
    cVarModel();
    cVarModel(const cGSLVector& theParam);
    cVarModel(const cVarModel& orig);
    cData& operator = (const cData & theData);
    virtual double mComputeVar(const cData& theData, int theNbCompute) const = 0; //passage par copie => ajouter référence pour ne pas recopier
    virtual cVarModel* ptrCopy() const = 0;
    virtual ~cVarModel();
private:

};

#endif /* CVARMODEL_H */

