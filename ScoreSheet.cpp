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
    os << "Player name: " << obj.playerName << "\t Points: " << obj.overallScore << endl;
    obj.doprint(os);
    os << "Failed throws:" << obj.numberOfFailedThrows << endl;
    return os;
}

int ScoreSheet::setTotal() {
    return calcTotal(numberOfFailedThrows, overallScore);
}