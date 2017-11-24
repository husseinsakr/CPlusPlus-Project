/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QwintoRow.h
 * Author: Hussein
 *
 * Created on November 23, 2017, 7:07 PM
 */

#ifndef QWINTOROW_H
#define QWINTOROW_H

#include "RollOfDice.h"

template <Colour colour> 
class QwintoRow { 
    Colour color;
    public:
        int arrayOfRolls[12];
        int &operator[] (int index) const;
        bool validate(int index) const;
        friend ostream &operator<< (ostream &os, const QwintoRow<colour> &obj);
};

#endif /* QWINTOROW_H */
