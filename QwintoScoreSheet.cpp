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
        
//helper method for setTotal
int QwintoScoreSheet::calcTotal() {
    return 1;
} 

bool QwintoScoreSheet::validate(RollOfDice &rollOfDice, Colour colour, int position){
    bool validate;
    
    switch (colour){
        case Colour::RED:
            validate = redRow.validate(position, rollOfDice);
        break;       

        case Colour::YELLOW:
            validate = yellowRow.validate(position, rollOfDice);
        break;

        case Colour::BLUE:
            validate = blueRow.validate(position, rollOfDice);
        break;
    }
    return validate;
}

