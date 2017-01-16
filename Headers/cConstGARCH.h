/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cConstGARCH.h
 * Author: paviotch
 *
 * Created on January 10, 2017, 11:12 AM
 */

#ifndef CCONSTGARCH_H
#define CCONSTGARCH_H

#include "cVarModel.h"


class cConstGARCH : public cVarModel {
public:
    cConstGARCH();
    cConstGARCH(const cConstGARCH& orig);
    
    cConstGARCH(const cGSLVector& theParam);
    virtual double mComputeVar(const cData& theData, int theNbCompute) const; //passage par copie => ajouter référence pour ne pas recopier
    virtual cGSLVector* mGradient(const cData& theData, int theGradSize, int theNbCompute, int theBeginIndex, const cGradient& thePrecGrad);
    virtual cVarModel* ptrCopy() const;
    virtual ~cConstGARCH();
    void VectorToRegArchParam(const cGSLVector& theSrcVect, uint theIndex);
private:

};

#endif /* CCONSTGARCH_H */

