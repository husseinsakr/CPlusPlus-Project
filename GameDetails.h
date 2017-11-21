/*
 * =================================
 * File: GameDetails.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef GAME_DETAILS
#define GAME_DETAILS
#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::string; using std::vector;

enum class Colour {RED, YELLOW, BLUE, GREEN, WHITE};

struct RandomDice{
	static constexpr int lowerBound = 1;
	static constexpr int upperBound = 6;
};

struct Dice {
	const Colour colour;
	int face;
	friend std::ostream& operator<< (std::ostream& os, const Dice& dice);
	void roll();
};

class RollOfDice {
	vector<Dice> diceVec;
public:
	operator int() const;
	void roll();
	RollOfDice pair(Dice& one, Dice& two);	
};

#endif /* GAME_DETAILS */