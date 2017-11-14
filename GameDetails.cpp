/*
 * =================================
 * File: GameDetails.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "GameDetails.h"

Dice::ostream& operator<< (ostream& os, const Dice&) {
	os << Dice.face << "\n";
	return os;
}
void Dice::roll() {
	int tmp = RandomDice::distribution(gen);
	this->face = tmp;
}