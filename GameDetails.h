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
	std::uniform_int_distribution<int> distribution(lowerBound, upperBound);
};

struct Dice {
	const Colour::colour;
	int face;
	void roll();
	friend ostream& operator<< (ostream& os, const Dice&);
};

class RollOfDice {
	vector<Dice> diceVec;
public:
	void roll();
	RollOfDice pair(Dice one, Dice two);
	operator int() const;
	
	
};


class QwintoScoreSheet: ScoreSheet {
public:
	friend ostream& operator<<(ostream& os, const QwintoScoreSheet& qwintoscoresheet);
	virtual ostream& print(ostream& os) const; 
};

class QwixxScoreSheet: ScoreSheet {
public:
	friend ostream& operator<<(ostream& os, const QwintoScoreSheet& qwixxscoresheet);
	virtual ostream& print(ostream& os) const;
	
};

#endif /* GAME_DETAILS */