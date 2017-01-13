
#include "cGradient.h"

cGradient::cGradient(int theSizeMean, int theSizeVar, int theSizeParams) {
    mGradientMean = new cGSLMatrix(theSizeMean + theSizeVar + theSizeParams, 1, 0);
    mGradientVar = new cGSLMatrix(theSizeMean + theSizeVar + theSizeParams, 1, 0);
}