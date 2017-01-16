/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGlobalVar.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 3:58 PM
 */

#ifndef CGLOBALVAR_H
#define CGLOBALVAR_H

#include "cVarModel.h"
#include <list>

using namespace std;

class cGlobalVar {
public:
    std::list<cVarModel*> mVar;
    cGlobalVar();
    cGlobalVar(const cGlobalVar& orig);
    double mComputeVar(const cData& theData, int theNbCompute) const;
    cGSLVector* mComputeGradient(int theNbCompute, const cData &theData, cGradient *theGrad);
    void mAddVar(cVarModel *theModel);
    int mSizeVar() const;
    void VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex);
    virtual ~cGlobalVar();
private:

};

#endif /* CGLOBALVAR_H */

