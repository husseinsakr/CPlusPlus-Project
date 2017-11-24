/*
 * =================================
 * File: QwintoRow.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWINTOROW_H
#define QWINTOROW_H

#include "RollOfDice.h"

template <Colour colour> 
class QwintoRow { 
    public:
        int arrayOfRolls[12];
        int &operator[] (int index) const;
        bool validate(int index) const;
        friend ostream &operator<< (ostream &os, const QwintoRow<colour> &obj);
};

#endif /* QWINTOROW_H */
