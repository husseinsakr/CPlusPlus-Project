/*
 * =================================
 * File: QwintoScoreSheet.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwintoScoreSheet.h"
//#define TEST_QWINTOSCORESHEET

#ifdef TEST_QWINTOSCORESHEET
int main() {
    QwintoScoreSheet* qss;
    qss = new QwintoScoreSheet();
    cout << *qss << endl;
    return 0;
}
#endif

//ostream& operator<< (ostream &os, const QwintoScoreSheet &obj){
    //return obj.doprint(os);
//}
    
QwintoScoreSheet::QwintoScoreSheet(){
    redRow = QwintoRow<Colour::RED>();
    blueRow = QwintoRow<Colour::BLUE>();
    yellowRow = QwintoRow<Colour::YELLOW>();
}

//helper method for setTotal
int QwintoScoreSheet::calcTotal() {
    int redRowEntries = 0, blueRowEntries = 0, yellowRowEntries = 0; //variables to store entries
    int max = 0; //used variable for the bonus columns
    
    for (auto x : redRow.arrayOfRolls) { //checking entries for red row
        if (x != 0) {
            redRowEntries++;
        }
    }
    if (redRowEntries == 9) //if entries = 9 entries than add last score to overallScore
        overallScore += redRow.arrayOfRolls[9];
    else
        overallScore += redRowEntries;
    
    for (auto x : blueRow.arrayOfRolls) { //checking entries for blue row
        if (x != 0) {
            blueRowEntries++;
        }
    }
    if (blueRowEntries == 9) //if entries = 9 entries than add last score to overallScore
        overallScore += blueRow.arrayOfRolls[9];
    else
        overallScore += blueRowEntries;
    
    for (auto x : yellowRow.arrayOfRolls) { //checking entries for yellow row
        if (x != 0) {
            yellowRowEntries++;
        }
    }
    if (yellowRowEntries == 9) //if entries = 9 entries than add last score to overallScore
        overallScore += yellowRow.arrayOfRolls[9];
    else
        overallScore += yellowRowEntries;
    
    if (redRow.arrayOfRolls[0] != 0 && yellowRow.arrayOfRolls[1] != 0 && blueRow.arrayOfRolls[2] != 0){ //checks first bonus column
        max = blueRow.arrayOfRolls[2];
        overallScore += max;
    }
    
    if (redRow.arrayOfRolls[1] != 0 && yellowRow.arrayOfRolls[2] != 0 && blueRow.arrayOfRolls[3] != 0){ //checks second bonus column
        max = redRow.arrayOfRolls[1];   
        overallScore += max;
    }
    
    if (redRow.arrayOfRolls[5] != 0 && yellowRow.arrayOfRolls[6] != 0 && blueRow.arrayOfRolls[7] != 0){ //checks third bonus column
        max = redRow.arrayOfRolls[5];
        overallScore += max;
    }
    
    if (redRow.arrayOfRolls[6] != 0 && yellowRow.arrayOfRolls[7] != 0 && blueRow.arrayOfRolls[8] != 0){ //checks fourth bonus column
        max = yellowRow.arrayOfRolls[7];
        overallScore += max;
    }
    
    if (redRow.arrayOfRolls[7] != 0 && yellowRow.arrayOfRolls[8] != 0 && blueRow.arrayOfRolls[9] != 0){ //checks fifth bonus column
        max = blueRow.arrayOfRolls[9];
        overallScore += max;
    }
    
    overallScore -= (numberOfFailedThrows * 5); // -5 score is removed per failed throw
    
    return overallScore;
} 

bool QwintoScoreSheet::validate(RollOfDice &rollOfDice, Colour colour, int position){
    bool validate = true;
    
    switch (colour){
        case Colour::RED:
            validate = redRow.validate(position, rollOfDice);
            if (position >= 0 && position <= 7 && validate) { //column overlap check
                if(yellowRow.arrayOfRolls[position + 1] == rollOfDice || blueRow.arrayOfRolls[position + 2] == rollOfDice){
                    cout << "Can't have a number repeat in an overlapping column!" << endl;
                    validate = false;
                }
            }
        break;       

        case Colour::YELLOW:
            validate = yellowRow.validate(position, rollOfDice);
            if (position >= 1 && position <= 8 && validate) { //column overlap check
                if(redRow.arrayOfRolls[position - 1] == rollOfDice || blueRow.arrayOfRolls[position + 1] == rollOfDice){
                    cout << "Can't have a number repeat in an overlapping column!" << endl;
                    validate = false;
                }
            }
        break;

        case Colour::BLUE:
            validate = blueRow.validate(position, rollOfDice);
            if (position >= 2 && position <= 9 && validate) { //column overlap check
                if(redRow.arrayOfRolls[position - 2] == rollOfDice || yellowRow.arrayOfRolls[position - 1] == rollOfDice){
                    cout << "Can't have a number repeat in an overlapping column!" << endl;
                    validate = false;
                }
            }
        break;
    }
    return validate;
}

bool QwintoScoreSheet::score(RollOfDice &rollOfDice, Colour colour, int position) {
    if (validate(rollOfDice, colour, position)){
            switch (colour){
            case Colour::RED:
                redRow[position] = rollOfDice;
                return true;
            break;       

            case Colour::YELLOW:
                yellowRow[position] = rollOfDice;
                return true;
            break;

            case Colour::BLUE:
                blueRow[position] = rollOfDice;
                return true;
            break;
            }
        }
        return false;
}

bool QwintoScoreSheet::operator! () {
	int elemCounter = 0;
	int rowCounter = 0;
	for (auto i : redRow.arrayOfRolls) {
		if (i != 0) {
			elemCounter++;
		}
	}
	if (elemCounter == 9) {
		rowCounter++;
	}
	elemCounter = 0;
	for (auto i : yellowRow.arrayOfRolls) {
		if (i != 0) {
			elemCounter++;
		}
	}
	
	if (elemCounter == 9) {
		rowCounter++;
	}
	elemCounter = 0;
	for (auto i : blueRow.arrayOfRolls) {
		if (i != 0) {
			elemCounter++;
		}
	}
	if (elemCounter == 9) {
		rowCounter++;
	}
	return (numberOfFailedThrows == 4 || rowCounter == 2); 	
}
    
