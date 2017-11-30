/*
 * =================================
 * File: QwixxScoreSheet.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwixxScoreSheet.h"

bool QwixxScoreSheet::validate(RollOfDice &rollOfDice, Colour colour, int position) {
    bool result;
    switch (colour) {
        case Colour::RED:
            if (this->redRow.container.at(position) = rollOfDice) {
                result = false;
            }
            result = true;     
        break;
        case Colour::YELLOW:
            if (this->redRow.container.at(position) = rollOfDice) {
                result = false;
            }
            result = true; 
        break;
        case Colour::GREEN:
            if (this->redRow.container.at(position) = rollOfDice) {
                result = false;
            }
            result = true; 
        break;
        case Colour::BLUE:
            if (this->redRow.container.at(position) = rollOfDice) {
                result = false;
            }
            result = true; 
        break;        
    }
    return result;
}
    
int QwixxScoreSheet::calcTotal(int numberOfFailedThrows, int overallScore) {
    return 1;
}
    
    //enters score returns booleans indicating if the dice can be scored
bool QwixxScoreSheet::score(RollOfDice &rollOfDice, Colour colour, int position) {
   return false; 
}

bool QwixxScoreSheet::operator! () {
        int elemCounter = 0;
        int rowCounter = 0;
        bool endRow = false;
	for (auto i : redRow.container) {
		if (i != 0) {
                    if (i == 12) {
                        endRow = true;
                    }
                    elemCounter++;
		}
	}
	if (elemCounter >= 5 && endRow) {
		rowCounter++;
	}
	elemCounter = 0;
        endRow = false;
        
	for (auto i : yellowRow.container) {
		if (i != 0) {
                    if (i == 12) {
                        endRow = true;
                    }
                    elemCounter++;
		}
	}
	
	if (elemCounter >= 5 && endRow) {
		rowCounter++;
	}
	elemCounter = 0;
        endRow = false;
	for (auto i : blueRow.container) {
		if (i != 0) {
                    if (i == 2) {
                        endRow = true;
                    }
                    elemCounter++;
		}
	}
	if (elemCounter >= 5 && endRow) {
		rowCounter++;
	}
        elemCounter = 0;
        endRow = false;
	for (auto i : greenRow.container) {
		if (i != 0) {
                    if (i == 2) {
                        endRow = true;
                    }
                    elemCounter++;
		}
	}
	if (elemCounter >= 5 && endRow) {
		rowCounter++;
	}
	return (!numberOfFailedThrows == 4 || !rowCounter == 2); 
}
