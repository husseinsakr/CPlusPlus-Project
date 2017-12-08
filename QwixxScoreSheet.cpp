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
//#define TEST_QWIXXSCORESHEET

#ifdef TEST_QWIXXSCORESHEET
int main() {
    QwixxScoreSheet* qxss;
    qxss = new QwixxScoreSheet();
    cout << *qxss << endl;
    return 0;
}
#endif

QwixxScoreSheet::QwixxScoreSheet() {
    redRow = QwixxRow<vector<int>, Colour::RED>();
    yellowRow = QwixxRow<vector<int>, Colour::YELLOW>();
    greenRow = QwixxRow<list<int>, Colour::GREEN>();
    blueRow = QwixxRow<list<int>, Colour::BLUE>();
}

bool QwixxScoreSheet::validate(RollOfDice &rollOfDice, Colour colour, int position) {
    bool result;
    int rd = static_cast<int>(rollOfDice);
    
    switch (colour) {
        //searches through the row for rd, if it finds it return false, cant
        //add a non unique score
        case Colour::RED:
            if (find(this->redRow.container.begin(),this->redRow.container.end(), rd) != this->redRow.container.end()) {
                result = false;
            }
            result = true;     
        break;
        case Colour::YELLOW:
            if (find(this->yellowRow.container.begin(),this->yellowRow.container.end(), rd) != this->yellowRow.container.end()) {
                result = false;
            }
            result = true; 
        break;
        case Colour::GREEN:
            if (find(this->greenRow.container.begin(),this->greenRow.container.end(), rd) != this->greenRow.container.end()) {
                result = false;
            }
            result = true; 
        break;
        case Colour::BLUE:
            if (find(this->blueRow.container.begin(),this->blueRow.container.end(), rd) != this->blueRow.container.end()) {
                result = false;
            }
            result = true; 
        break;        
    }
    return result;
}
    
int QwixxScoreSheet::calcTotal() {
    int result = 0; //score to be returned
    int pointCounter = 0; //for adding points to overall
    int entryCounter = 0; //for determining if you have to add 1 more for a lock
    bool lockTrack = false; //tracking if the final element in the row has been added
    
    for (auto x : this->redRow.container) {
        if (x != 0) {
            entryCounter++;
            pointCounter++;
            overallScore += pointCounter;
        }
        if (x == 12) {
            lockTrack = true;
        }
    }
    if (lockTrack && entryCounter >= 5) {
        pointCounter++;
        overallScore += pointCounter;
    }
    pointCounter = 0;//Reset both counters for new rows
    entryCounter = 0;
    for (auto x : this->yellowRow.container) {
        if (x != 0) {
            entryCounter++;
            pointCounter++;
            overallScore += pointCounter;
        }
        if (x == 12) {
            lockTrack = true;
        }
    }
    if (lockTrack && entryCounter >= 5) {
        pointCounter++;
        overallScore += pointCounter;
    }
    pointCounter = 0;
    entryCounter = 0;
    for (auto x : this->greenRow.container) {
        if (x != 0) {
            entryCounter++;
            pointCounter++;
            overallScore += pointCounter;
        }
        if (x == 2) {
            lockTrack = true;
        }
    }
    if (lockTrack && entryCounter >= 5) {
        pointCounter++;
        overallScore += pointCounter;
    }
    pointCounter = 0;
    entryCounter = 0;
    for (auto x : this->blueRow.container) {
        if (x != 0) {
            entryCounter++;
            pointCounter++;
            overallScore += pointCounter;
        }
        if (x == 2) {
            lockTrack = true;
        }
    }
    if (lockTrack && entryCounter >= 5) {
        pointCounter++;
        overallScore += pointCounter;
    }
    result = overallScore - (5*numberOfFailedThrows);
    return result;
}
    
    //enters score returns booleans indicating if the dice can be scored
bool QwixxScoreSheet::score(RollOfDice &rollOfDice, Colour colour, int position) {
    list<int>::iterator lFront; //list iterator for green and blue rows
    int rd = static_cast<int>(rollOfDice);
    //if the roll is validated and unique, goes to that position in the row
    //and adds the rollofdice
    if (validate(rollOfDice, colour, position)) {
        switch (colour) {
            case Colour::RED:
                this->redRow.container.at(position) += rollOfDice;
                return true;
            break;
            case Colour::YELLOW:
                this->yellowRow.container.at(position) += rollOfDice;
                return true;
            break;
            //insertion process different for list, need to use iterator and insert
            case Colour::GREEN:
                lFront = this->greenRow.container.begin();
                advance(lFront, position);
                this->greenRow.container.insert(lFront, rd);
                return true;
            break;
            case Colour::BLUE:
                lFront = this->blueRow.container.begin();
                advance(lFront, position);
                this->blueRow.container.insert(lFront, rd);
                return true;
            break;
        }
    }
    return false; 
}

bool QwixxScoreSheet::operator! () {
        int elemCounter = 0;
        int rowCounter = 0;
        bool endRow = false;
        //checks to see if there are at least 5 elements in each row
        //if 2 or 12 depending on the row are locked changes endRow
        //need both to increment rowCounter to simulate a locked row
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
