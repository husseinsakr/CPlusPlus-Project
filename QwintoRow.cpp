/*
 * =================================
 * File: QwintoRow.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwintoRow.h"

//subscript operator [] returns memory location of array at certain index
template <Colour colour>
int &QwintoRow<colour>::operator[] (int index) const { 
    if (validate(index))
        return arrayOfRolls[index];
    else
        cout << "Cannot make this insertion! Index out of bounds!" << endl;
}

template <Colour colour>
bool QwintoRow<colour>::validate(int index) const{
    //method that validates if you can insert a rollOfDice to fixed array
    return index <= 12;
}

template <Colour colour>
ostream &operator<< (ostream &os, const QwintoRow<colour> &obj) {
    //loop through QwintoRow array which contains RollofDice entries
    //and print the value based on int conversion
    for (RollOfDice r : obj.arrayOfRolls){ 
        os << static_cast<int>(r) << " ";
    }
    os << endl;
    return os;
 }

