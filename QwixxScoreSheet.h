/*
 * =================================
 * File: QwixxScoreSheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H

#include "QwixxRow.h"
#include "ScoreSheet.h"


class QwixxScoreSheet : public ScoreSheet {
    
    bool validate(RollOfDice &rollOfDice, Colour colour, int position);
    
    int calcTotal(int numberOfFailedThrows, int overallScore);
    
    
    bool score(RollOfDice &rollOfDice, Colour colour, int position);
    bool operator! ();
    ostream& doprint(ostream& os) const {
        return os;
    }
     
    //functions
    friend ostream& operator<< (ostream &os, const ScoreSheet &obj);
};

#endif /* QWIXXSCORESHEET_H */
