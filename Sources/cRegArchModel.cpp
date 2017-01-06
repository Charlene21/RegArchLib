/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cRegArchModel.cpp
 * Author: paviotch
 * 
 * Created on December 2, 2016, 3:51 PM
 */

#include "cRegArchModel.h"

cRegArchModel::cRegArchModel() {
    this->mGlobalMean = new cGlobalMean();
}

cRegArchModel::cRegArchModel(const cRegArchModel& orig) {
}

cRegArchModel::~cRegArchModel() {
}

