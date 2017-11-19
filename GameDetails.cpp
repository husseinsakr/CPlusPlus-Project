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

std::ostream& operator<< (std::ostream& os, const Dice& dice) {
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
RollOfDice::operator int() const {
	int result = 0;
	for (Dice d : diceVec) {
		result += d.face;
	}
	return result;
}
void RollOfDice::roll() {
	for (Dice d : diceVec) {
		d.Dice::roll();
	}
}
RollOfDice RollOfDice::pair(Dice& one, Dice& two) {
	RollOfDice rd;
	diceVec.push_back(one);
	diceVec.push_back(two);
	return rd;
}