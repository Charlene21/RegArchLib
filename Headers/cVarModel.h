/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cVarModel.h
 * Author: paviotch
 *
 * Created on December 2, 2016, 4:23 PM
 */

#ifndef CVARMODEL_H
#define CVARMODEL_H

class cVarModel {
public:
    
    cVarModel();
    cVarModel(const cVarModel& orig);
    double mComputeVar();
    virtual ~cVarModel();
private:

};

#endif /* CVARMODEL_H */

