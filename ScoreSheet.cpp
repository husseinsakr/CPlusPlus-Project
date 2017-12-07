/*
 * =================================
 * File: ScoreSheet.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "ScoreSheet.h"

ostream &operator<< (ostream &os, const ScoreSheet &obj) {
    os << "Player name:   " << obj.playerName ;
    if(obj.overallScore != 0)  //doesn't show points until end of game scoreSheet
        os << "\t\t Points: " << obj.overallScore << endl;
    else
        os << endl;
    obj.doprint(os);
    os << "Failed throws: ";
    for (int i = 1; i <= obj.numberOfFailedThrows; i++)
        os << i << " ";
    os << endl << endl;
    return os;
}

int ScoreSheet::setTotal() {
    return calcTotal();
}