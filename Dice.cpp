/*
 * =================================
 * File: Dice.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "Dice.h"

//Function implementation for Dice class
ostream &operator<< (ostream &os, const Dice &dice) {  //output operator overloaded
	os << dice.face;
	return os;
}
void Dice::roll() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(RandomDice::lower, RandomDice::upper);
	int tmp = dis(gen);
	this->face = tmp;
}

