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
	int numberOfFailedThrows; //number of failed throws by player
	int overallScore; //score of player, current and final
        string playerName; //stores player name in Scoresheet
        
        //functions
        //enters score returns booleans indicating if the dice can be scored
	virtual bool score(int &RollOfDice, Colour colour, int position = -1);
        
        //sets and returns the points for the final score
        virtual int setTotal(); 
        
        //helper method for setTotal
        virtual int calcTotal(); 
        
        friend ostream &operator<< (ostream &os, const ScoreSheet &obj);
};

#endif /* SCORESHEET_H */
