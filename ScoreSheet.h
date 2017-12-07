/*
 * =================================
 * File: ScoreSheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef SCORESHEET_H
#define SCORESHEET_H

#include "RollOfDice.h"
#include "AllIncludes.h"

class ScoreSheet {    
    
public:
    
    //instance variables
    int numberOfFailedThrows = 0; //number of failed throws by player
    int overallScore = 0; //score of player, current and final
    string playerName; //stores player name in Scoresheet
    
    virtual bool validate(RollOfDice &rollOfDice, Colour colour, int position) = 0;
    
    virtual int calcTotal() = 0; //helper method for setTotal
    
    //enters score returns booleans indicating if the dice can be scored
    virtual bool score(RollOfDice &rollOfDice, Colour colour, int position = -1) = 0;
    virtual bool operator! () = 0; //returns true if the scoresheet indicates the game is done
    virtual ostream& doprint(ostream& os) const = 0;
     
    //functions
    friend ostream& operator<< (ostream &os, const ScoreSheet &obj);
    virtual int setTotal(); //sets and returns the points for the final score
    
        
};

#endif /* SCORESHEET_H */
