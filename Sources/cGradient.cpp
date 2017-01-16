
#include "cGradient.h"

cGradient::cGradient(int theSizeMean, int theSizeVar, int theSizeParams) {
    mGradientMean = new cGSLMatrix(theSizeMean + theSizeVar + theSizeParams, 1, 0);
    mGradientVar = new cGSLMatrix(theSizeMean + theSizeVar + theSizeParams, 1, 0);
}

cGradient :: cGradient(const cGradient &origin){
    mGradientMean = new cGSLMatrix(*(origin.mGradientMean));
    mGradientVar = new cGSLMatrix(*(origin.mGradientVar));
}