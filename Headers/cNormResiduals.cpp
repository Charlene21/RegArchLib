#include <gsl/gsl_randist.h>

#include "cNormResiduals.h"

cNormResiduals::cNormResiduals() {
    
}

cNormResiduals::cNormResiduals(const cResiduals& orig) {
    
}

double cNormResiduals::mDensite(double x, bool logarithme) const {
    // Fonction de la libraiie GSL qui calcule la densité gaussienne
    // On précise juste le sigma = 1
    double res = gsl_ran_gaussian_pdf(x, 1);
    if (logarithme) {
        return log(res);
    } else {
        return res;
    }
}

cGSLVector* cNormResiduals::mSimul(int size) {
    cGSLVector* myVect = new cGSLVector(size);
    gsl_rng* rng = gsl_rng_alloc(gsl_rng_default);
    for (int i = 0; i < size; i++) {
        myVect[i] = gsl_ran_gaussian(rng, 1);
    } 
    return myVect;
}

void cNormResiduals::mGradient(cData& data, cGSLVector& vect) const {
    
}