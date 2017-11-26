/*
 * =================================
 * File: QwintoRow.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwintoRow.h"

//method that validates if you can insert at a certain index
template <Colour colour>
bool QwintoRow<colour>::validate(int index, RollOfDice &rollOfDice) const{
    int illegalIndex; //can't place rollOfDice in this index
    
    switch(colour) { //each QwintoRow colour have a different illegal index
        case Colour::RED:
            illegalIndex = 3; 
        break;       
        
        case Colour::YELLOW:
            illegalIndex = 5;
        break;
        
        case Colour::BLUE:
            illegalIndex = 4;
        break;
    }
    
    if (index == illegalIndex || index < 0 || index > 9){ 
        return false;    
    }
    
    if (index != 0){
        int smallerThanRoll = arrayOfRolls[0];
        for (int i = 0; i < index; i++){ //check if all the rolls on the left are smaller
            if (i == illegalIndex){ i++; }

            if(i != index) {
                smallerThanRoll = arrayOfRolls[i];
                if (smallerThanRoll >= rollOfDice)
                    return false;
            }
        }
    }
    
    if (index != 9){ 
        int biggerThanRoll = arrayOfRolls[index + 1];
        for (int i = index + 1; i < 10; i++) { //check if all rolls on the right of the index are bigger
            if (i == illegalIndex){ i++; }
            if(i != index) {
                biggerThanRoll = arrayOfRolls[i];
                if (biggerThanRoll >= rollOfDice)
                    return false;
            }
        }
    }
    
    return true;
}
