/* 
 * File:   cGradient.h
 * Author: gononl
 *
 * Created on January 13, 2017, 1:42 PM
 */

#ifndef CGRADIENT_H
#define	CGRADIENT_H

#include "StdAfxVectorAndMatrix.h"

using namespace VectorAndMatrixNameSpace;

class cGradient {
public:
    cGSLMatrix* mGradientMean;
    cGSLMatrix* mGradientVar;
    /* Ordre des parametres
     * cARMA
     * AR
     * MA
     * cGARCH
     * ARCH
     * GARCH
     * Paramètres loi
     */
    cGradient(int sizeMean, int sizeVar, int sizeParams);
    
    ~cGradient();
};

#endif	/* CGRADIENT_H */

