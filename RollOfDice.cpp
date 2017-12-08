/*
 * =================================
 * File: RollOfDice.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "RollOfDice.h"

//Function implementation for RollOfDice class
RollOfDice::operator int() const{
	int result = 0;
	for (Dice d : diceVec) {
		result += d.face;
	}
	return result;
}
void RollOfDice::roll() {
	for (Dice &d : diceVec) {
		d.roll(); //should be d.roll()
	}
}
RollOfDice RollOfDice::pair(Dice one, Dice two) {
	RollOfDice rd;
	rd.diceVec.push_back(one);
	rd.diceVec.push_back(two);
	return rd;
}
ostream &operator<< (ostream& os, RollOfDice& rd) {
	int i = 1;
        int score = 0;
        string diceColour;
        
	for (Dice d : rd.diceVec) {
            switch(d.colour){
                case Colour::RED:
                    diceColour = "Red";
                break;
                case Colour::YELLOW:
                    diceColour = "Yellow";
                break;
                case Colour::GREEN:
                    diceColour = "Green";
                break;
                case Colour::BLUE:
                    diceColour = "Blue";
                break;
                case Colour::WHITE:
                    diceColour = "White";
                break;
            }
            os << "Dice " << i << " with colour " << diceColour << " rolled: " << d.face << endl;
            score += d.face;
            i++;
	}
        os << "You have to score: " << score << " in qwinto!"<< endl;
	return os;
}