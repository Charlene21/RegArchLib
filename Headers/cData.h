/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cData.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 4:31 PM
 */

#ifndef CDATA_H
#define CDATA_H
#include "StdAfxVectorAndMatrix.h"

using namespace VectorAndMatrixNameSpace;

class cData {
public:
    cGSLVector* mYt;
    cGSLVector* mUt;
    cGSLVector* mHt;
    cGSLVector* mEt;
    cGSLVector* mMt;
    
    cData();
    cData(const cData& orig);
    virtual ~cData();
private:

};

#endif /* CDATA_H */

