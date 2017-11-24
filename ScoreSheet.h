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
protected:
        //instance variables
	int numberOfFailedThrows; //number of failed throws by player
	int overallScore; //score of player, current and final
        string playerName; //stores player name in Scoresheet
        
        //functions
	virtual bool score(int &RollOfDice, Colour colour, int position = -1); //enters score
        virtual int setTotal(); //sets and returns the points for the final score
        virtual int calcTotal(); //helper method for setTotal
public:

};

#endif /* SCORESHEET_H */
