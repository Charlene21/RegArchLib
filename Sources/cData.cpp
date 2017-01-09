/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cData.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 4:31 PM
 */

#include "cData.h"

cData::cData() {
    mEt = new cGSLVector(1,1);
    mHt = new cGSLVector(1,1);
    mYt = new cGSLVector(1,1);
    mUt = new cGSLVector(1,1);
    mMt = new cGSLVector(1,1);
}

cData::cData(const cData& orig) {
}

cData::~cData() {
}

