/*
 * =================================
 * File: Dice.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef GAME_H
#define GAME_H

#include "RandomDice.h"
#include "Colour.h"
#include "AllIncludes.h"

struct Dice {
	const Colour colour; //colour of dice
	int face; //face of dice
	friend ostream &operator<< (ostream &os, const Dice &dice); //prints face of dice
	void roll(); //changes face of dice between 1 and 6
};



#endif /* GAME_H */
