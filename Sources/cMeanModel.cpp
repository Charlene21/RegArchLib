/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cMeanModel.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 4:07 PM
 */

#include "cMeanModel.h"

cMeanModel::cMeanModel() {

}

cMeanModel::cMeanModel(const cGSLVector& theParam) {
    mParams = new cGSLVector(theParam);
}

cMeanModel::cMeanModel(const cMeanModel& orig) {
    mParams = new cGSLVector(*(orig.mParams));
    
}

int cMeanModel::mGetSize() {
    return this->mParams->GetSize();
}

cMeanModel::~cMeanModel() {
}

cData& cMeanModel::operator = (const cData & theData){
    
}


