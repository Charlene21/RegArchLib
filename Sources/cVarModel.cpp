/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cVarModel.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 4:23 PM
 */

#include "cVarModel.h"

cVarModel::cVarModel() {
}

cVarModel::cVarModel(const cGSLVector& theParam) {
    mParams = new cGSLVector(theParam);
}

cVarModel::cVarModel(const cVarModel& orig) {
}

cData& cVarModel::operator = (const cData & theData){
    
}

cVarModel::~cVarModel() {
}

