/*
 * =================================
 * File: RollOfDice.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H

#include "Dice.h"

class RollOfDice {
	vector<Dice> diceVec;
public:
	operator int() const;
	void roll(); //calls roll on all the dice in the container
	RollOfDice pair(Dice& one, Dice& two);	
	friend ostream &operator<< (ostream& os, RollOfDice &rd);
};




#endif /* ROLLOFDICE_H */
