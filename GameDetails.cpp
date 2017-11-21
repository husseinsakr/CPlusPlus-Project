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

#include <iostream>
#include <random>
#include "GameDetails.h"

using std::ostream; using std::endl;

//Function implementation for Dice class
ostream& operator<< (ostream& os, const Dice& dice) {
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

//Function implementation for RollOfDice class
RollOfDice::operator int() const{
	int result = 0;
	for (Dice d : diceVec) {
		result += d.face;
	}
	return result;
}
void RollOfDice::roll() {
	for (Dice& d : diceVec) {
		d.Dice::roll();
	}
}
RollOfDice RollOfDice::pair(Dice& one, Dice& two) {
	RollOfDice rd;
	diceVec.push_back(one);
	diceVec.push_back(two);
	return rd;
}
ostream& operator<< (ostream& os, RollOfDice& rd) {
	int i = 1;
	for (Dice d : rd.diceVec) {
		os << "Dice " << i << " rolled: " << d.face << endl;
		i++;
	}
	return os;
}