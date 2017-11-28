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
    
    virtual bool validate(RollOfDice &rollOfDice, Colour colour, int position) = 0;
    
    virtual int calcTotal(int numberOfFailedThrows, int overallScore) = 0; //helper method for setTotal
    
    //enters score returns booleans indicating if the dice can be scored
    virtual bool score(RollOfDice &rollOfDice, Colour colour, int position = -1) = 0;
    
public: 
        //instance variables
	int numberOfFailedThrows; //number of failed throws by player
	int overallScore; //score of player, current and final
        string playerName; //stores player name in Scoresheet
        
        //functions
        
        //sets and returns the points for the final score
        virtual int setTotal(); 
       
        friend ostream& operator<< (ostream &os, const ScoreSheet &obj);
        
        //virtual bool operator! (); //returns true if the scoresheet indicates the game is done
};

#endif /* SCORESHEET_H */
