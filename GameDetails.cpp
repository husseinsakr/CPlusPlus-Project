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
QwintoRow<Colour>::int& operator[](int index) const {
	return a[index];
}
QwintoRow<Colour>::bool validate(int index) const {
	//False when the index is outside the preset max length of 12
	//for QwintoRow
	return index <= 12; 
}
template <typename T>
std::ostream& operator<< (std::ostream& os, const QwintoRow<T>& obj) {
	//loop through QwintoRow array which contains RollofDice entries
	//and print the value based on int conversion
	for (RollOfDice r : QwintoRow<Colour>.a) {
		os << static_cast<int> r << ' ';
	}
	os << endl;
	
}
