/*
 * =================================
 * File: QwixxScoreSheet.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwixxScoreSheet.h"

bool QwixxScoreSheet::validate(RollOfDice &rollOfDice, Colour colour, int position) {
    return false;
}
    
int QwixxScoreSheet::calcTotal(int numberOfFailedThrows, int overallScore) {
    return 1;
}
    
    //enters score returns booleans indicating if the dice can be scored
bool QwixxScoreSheet::score(RollOfDice &rollOfDice, Colour colour, int position = -1) {
   return false; 
}

bool QwixxScoreSheet::operator! () {
    return false;
}
