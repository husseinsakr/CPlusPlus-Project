/*
 * =================================
 * File: QwintoScoreSheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H

#include "QwintoRow.h"
#include "ScoreSheet.h"


class QwintoScoreSheet: public ScoreSheet {
public:
    QwintoRow<Colour::RED> redRow;
    QwintoRow<Colour::BLUE> blueRow;
    QwintoRow<Colour::YELLOW> yellowRow;
    
    //enters score returns booleans indicating if the dice can be scored
    bool score(int &RollOfDice, Colour colour, int position = -1);
        
    //sets and returns the points for the final score
    int setTotal(); 
        
    //helper method for setTotal
    int calcTotal(); 

};



#endif /* QWINTOSCORESHEET_H */
