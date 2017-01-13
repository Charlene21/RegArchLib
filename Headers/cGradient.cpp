
#include "cGradient.h"

cGradient::cGradient(int theSizeMean, int theSizeVar, int theSizeParams) {
    mGradient = new cGSLMatrix(theSizeMean + theSizeVar + theSizeParams, 1, 0);
}