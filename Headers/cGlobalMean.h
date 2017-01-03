/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cGlobalMean.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 3:54 PM
 */

#ifndef CGLOBALMEAN_H
#define CGLOBALMEAN_H
#include <list>
#include "cMeanModel.h"

class cGlobalMean {
public:
    std::list<cMeanModel *> mMean;
    cGlobalMean();
    cGlobalMean(const cGlobalMean& orig);
    double mComputeMean();
    double mGradient();
    virtual ~cGlobalMean();
private:

};

#endif /* CGLOBALMEAN_H */

