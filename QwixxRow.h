/*
 * =================================
 * File: QwixxRow.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

 
 
#ifndef QWIXXROW_H
#define QWIXXROW_H
 
#include "AllIncludes.h"
#include "RollOfDice.h"
 
template <class T, Colour colour>
class QwixxRow {
    public:
	T container = {0,0,0,0,0,0,0,0,0,0,0};
        
	QwixxRow operator+= (const RollOfDice& rollofdice){
            //iterators of type depending on row initialized to allow for inserting
            //into the container
           const vector<int>::iterator vFront = container.begin();
           const list<int>::iterator lFront = container.begin();
            bool add = true;
             string msg = "Your roll has more than 2 dice and can't be used to scored";
		if (rollofdice.diceVec.size() > 2 ) {
                    throw length_error(msg);
		}
                
                int rd = static_cast<int>(rollofdice);
              
               
                switch (colour) {
                    
                    case Colour::RED: case Colour::YELLOW:
                        //if it is already present in the container dont add again
                        if (find(container.begin(), container.end(), rd) != container.end()) {
                            return *this;
                        }
                        else {
                            //if values are present to the right of this position dont add
                            for (int i = (rd - 2); i < 11; i++) {
                                advance(vFront, i);
                                if (*vFront != 0) {
                                    add = false;
                                }
                            }
                            if (add) {
                                container.insert(vFront, rd);
                             
                            }
                            return *this; 
                            
                        }
                    break;
                    
                   
                    case Colour::GREEN: case Colour::BLUE:
                       if (find(container.begin(), container.end(), rd) != container.end()) {
                            return *this;
                        }
                       else {
                           for (int i = (rd-2); i > 0; i--) {
                               advance(lFront, i);
                               if (*lFront != 0) {
                                    add = false;
                                }
                           }
                           if (add) {
                               container.insert(lFront, rd);
                                 
                           }
                            return *this; 
                           
                       }
                    break;
                   
                }
                 
            //return *this;           
    
        };
        
		
        
	friend ostream& operator<< (ostream &os,const QwixxRow &obj) {
            string output; string tmp;
            output = "|";
            int y = 0;
            int entryCounter = 0;
            
            switch (colour) {
                case Colour::RED: case Colour::YELLOW:
                    entryCounter = 0;
                    y = 2;
                    for (auto x : obj.container) {
                        if (x == 0 && y < 10) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                        }
                        else if (x == 0 && y > 9) {
                            tmp = to_string(y) + "|";
                            output += tmp;
                        }
                        else if (x != 0) {
                            entryCounter++;
                            tmp = "XX|";
                            output += tmp;
                        }
                        
                        y++;   
                    }
                    
                    if (entryCounter == 5) {
                        output += " L";
                    }
                    else {
                        output += " U";
                    }
                    os << output;
                break;
                
                case Colour::GREEN: case Colour::BLUE:
                    entryCounter = 0;
                    y = 12;
                    for (auto x : obj.container) {
                        if (x == 0 && y < 10) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                        }
                        else if (x == 0 && y > 9) {
                            tmp = to_string(y) + "|";
                            output += tmp;
                        }
                        else if (x != 0) {
                            entryCounter++;
                            tmp = "XX|";
                            output += tmp;
                        }
                        
                        y--;
                    }
                  
                    if (entryCounter == 5) {
                        output += " L";
                    }
                    else {
                        output += " U";
                    }
                    os << output;
                break; 
             return os;
            }
        }
    };
#endif/* QWIXXROW_H */
    