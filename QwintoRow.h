/*
 * =================================
 * File: QwintoRow.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWINTOROW_H
#define QWINTOROW_H

#include "RollOfDice.h"

template <Colour colour> 
class QwintoRow { 
    public:
        int arrayOfRolls[10] = {0,0,0,0,0,0,0,0,0,0};
        
        bool validate(int index, RollOfDice &rollOfDice) const{
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
    
            if (index == illegalIndex || index < 0 || index > 9){ //check if the index is in illegalIndex
                cout << "Cant place rolls in an illegal spot!" << endl;
                return false;    
            }
    
            if (index != 0){
                int smallerThanRoll = arrayOfRolls[0];
                for (int i = 0; i < index; i++){ //check if all the rolls on the left are smaller
                    if (i == illegalIndex){ i++; }

                    if(i != index && arrayOfRolls[i] != 0) {
                        smallerThanRoll = arrayOfRolls[i];
                        if (smallerThanRoll >= rollOfDice){
                            cout << "There is a bigger number on the left!" << endl;
                            return false;
                        }
                    }
                }
            }
    
            if (index != 9){ 
                int biggerThanRoll = arrayOfRolls[index + 1];
                for (int i = index + 1; i < 10; i++) { //check if all rolls on the right of the index are bigger
                    if (i == illegalIndex){ i++; }
                    if(i != index && arrayOfRolls[i] != 0) {
                        biggerThanRoll = arrayOfRolls[i];
                        if (biggerThanRoll >= rollOfDice){
                            cout << "There is a smaller number on the right!" << endl;
                            return false;
                        }
                    }
                }
            }
    
            return true;
        }
        
        int &operator[] (const int index){
                return arrayOfRolls[index];
        }
        
        friend ostream& operator<< (ostream &os, const QwintoRow &obj) {
        //loop through QwintoRow array which contains RollofDice entries
        //and print the value based on int conversion
            string output; string tmp;
            output += "|";
            int i = 0;
			
            switch (colour) {
                    case Colour::RED:
                        i = 0; //refers to position colomns in row
                        for (int r : obj.arrayOfRolls){ 
                            //for printing parts of the row that are followed by % and
                            //for numbers less than 10 that need the extra space
                            if (r <= 9 && (i == 0 || i == 1 || i == 4 || i == 5) && i != 3) {
                                if (r == 0)
                                    tmp = "  %";
                                else 
                                    tmp = " " + to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is less than 10 and not one that is 
                            //followed by a %
                            else if (r <= 9 && (i != 0 || i != 1 || i != 4 || i != 5)&& i != 3) {
                                if (r == 0)
                                    tmp = "  |";
                                else 
                                    tmp = " " + to_string(r) + "|";
                                output += tmp;
                            }
                            //for the invalid row
                            else if (i == 3) {
                                tmp = "XX|";
                                output += tmp;
                            }
                            //when the number is greater than 9 and is followed by %
                            else if (r >= 10 && (i == 0 || i == 1 || i == 4 || i == 5) && i != 3) {
                                tmp = to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is greater than 9 and not followed by %
                            else if (r >= 9 && (i != 0 || i != 1 || i != 4 || i != 5) && i != 3) {
                                tmp = to_string(r) + "|";
                                output += tmp;
                            }
                            i++;
                        }
                        os << output;
                    break;
                    
                    case Colour::YELLOW:
                        i = 0; //refers to position colomns in row
                        for (int r : obj.arrayOfRolls){ 
                            //for printing parts of the row that are followed by % and
                            //for numbers less than 10 that need the extra space
                            if (r <= 9 && (i == 6 || i == 7) && i != 5) {
                                if (r == 0)
                                    tmp = "  %";
                                else 
                                    tmp = " " + to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is less than 10 and not one that is 
                            //followed by a %
                            else if (r <= 9 && (i != 6 || i != 7) && i != 5) {
                                if (r == 0)
                                    tmp = "  |";
                                else 
                                    tmp = " " + to_string(r) + "|";
                                output += tmp;
                            }
                            //for the invalid row
                            else if (i == 5) {
                                tmp = "XX|";
                                output += tmp;
                            }
                            //when the number is greater than 9 and is followed by %
                            else if (r >= 10 && (i == 6 || i == 7) && i != 5) {
                                tmp = to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is greater than 9 and not followed by %
                            else if (r >= 9 && (i != 6 || i != 7) && i != 5) {
                                tmp = to_string(r) + "|";
                                output += tmp;
                            }
                            i++;
                        }
                        os << output;
                    break;
                    
                    case Colour::BLUE:
                        i = 0; //refers to position colomns in row
                        for (int r : obj.arrayOfRolls){ 
                            //for printing parts of the row that are followed by % and
                            //for numbers less than 10 that need the extra space
                            if (r <= 9 && (i == 1 || i == 2 || i == 8 || i == 9) && i != 4) {
                                 if (r == 0)
                                    tmp = "  %";
                                else 
                                    tmp = " " + to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is less than 10 and not one that is 
                            //followed by a %
                            else if (r <= 9 && (i != 1 || i != 2 || i != 8 || i != 9) && i != 4) {
                                if (r == 0)
                                    tmp = "  |";
                                else 
                                    tmp = " " + to_string(r) + "|";
                                output += tmp;
                            }
                            //for the invalid row
                            else if (i == 4) {
                                tmp = "XX|";
                                output += tmp;
                            }
                            //when the number is greater than 9 and is followed by %
                            else if (r >= 10 && (i == 1 || i == 2 || i == 8 || i == 9) && i != 4) {
                                tmp = to_string(r) + "%";
                                output += tmp;
                            }
                            //when the number is greater than 9 and not followed by %
                            else if (r >= 9 && (i != 1 || i != 2 || i != 8 || i != 9) && i != 4) {
                                tmp = to_string(r) + "|";
                                output += tmp;
                            }
                            i++;
                        }
                        os << output;
                    break;		
            }
            return os;
        }
};

#endif /* QWINTOROW_H */
