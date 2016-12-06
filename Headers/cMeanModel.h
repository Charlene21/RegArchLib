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
#include "StdAfxVectorAndMatrix.h"
using namespace VectorAndMatrixNameSpace;

class cMeanModel {
public:
    
    cGSLVector mParams;
    cMeanModel();
    cMeanModel(const cMeanModel& orig);
    cData& operator = (const cData & data);
    virtual double mComputeMean(cData *data, int nbCompute);
    virtual ~cMeanModel();
private:

};

#endif /* CMEANMODEL_H */

