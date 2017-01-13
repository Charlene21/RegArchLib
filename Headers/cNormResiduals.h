/* 
 * File:   cNormResiduals.h
 * Author: gononl
 *
 * Created on January 9, 2017, 11:50 AM
 */

#ifndef CNORMRESIDUALS_H
#define	CNORMRESIDUALS_H
#include "StdAfxVectorAndMatrix.h"
#include "cData.h"
#include "cResiduals.h"
using namespace VectorAndMatrixNameSpace;

class cNormResiduals : public cResiduals {
public:
    cGSLVector mParams;
    cNormResiduals();
    cNormResiduals(const cResiduals& orig);
    cGSLVector* mSimul(int size);
    double mDensite(double, bool logarithme) const;
    void mGradient(cData &data, cGSLVector &vect) const;
    virtual ~cNormResiduals();
};


#endif	/* CNORMRESIDUALS_H */

