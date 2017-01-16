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

void cNormResiduals::mSimul(cData *theData, int size) {
    gsl_rng* rng = gsl_rng_alloc(gsl_rng_default);
    for (int i = 0; i < size; i++) {
       theData->mEt[i] = gsl_ran_gaussian(rng, 1);
    }
}

void cNormResiduals::mGradient(cData& data, cGSLVector& vect) const {
    
}

cNormResiduals::~cNormResiduals() {
}