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
        int arrayOfRolls[10] = {0,0,0,0,0,0,0,0,0,0};
        
        bool validate(int index, RollOfDice &rollOfDice) const;
        
        int &operator[] (const int index){
                return arrayOfRolls[index];
        }
        
        friend ostream &operator<< (ostream &os, const QwintoRow &obj) {
        //loop through QwintoRow array which contains RollofDice entries
        //and print the value based on int conversion
            for (int r : obj.arrayOfRolls){ 
                os << r << " ";
            }
            os << endl;
            return os;
        }
};

#endif /* QWINTOROW_H */
