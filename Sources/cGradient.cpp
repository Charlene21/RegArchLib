
#include "cGradient.h"

cGradient::cGradient(int theSizeMean, int theSizeVar, int theSizeParams) {
    mGradientMean = new cGSLVector(theSizeMean + theSizeVar + theSizeParams, 0);
    mGradientVar = new cGSLVector(theSizeMean + theSizeVar + theSizeParams, 0);
}