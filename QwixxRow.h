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
 
#include <list>
#include "AllIncludes.h"
#include "RollOfDice.h"
 
template <class T, Colour colour>
class QwixxRow {
    T container = {0,0,0,0,0,0,0,0,0,0,0};
    
    
    public:
	
	QwixxRow operator+= (const RollOfDice& rollofdice){
             string msg = "Your roll has more than 2 dice and can't be used to scored";
		if (rollofdice.diceVec.size() > 2 ) {
                    throw length_error(msg);
		}
                
                int rd = static_cast<int>(rollofdice);
              
               
                switch (colour) {
                    
                    case Colour::RED: case Colour::YELLOW:
                        if (find(container.begin(), container.end(), rd) != container.end()) {
                            return *this;
                        }
                        else {
                            
                            container.at(rd - 2) = rd;
                            cout << "inserting RD: " << rd << " into Vector container" << endl;
                            
                            return *this; 
                            
                        }
                    break;
                    
                   
                    case Colour::GREEN: case Colour::BLUE:
                       if (find(container.begin(), container.end(), rd) != container.end()) {
                            return *this;
                        }
                       else {
                        
                            container.at(rd - 2) = rd;
                            cout << "inserting RD: " << rd << " into List container" << endl;
                            cout << "List container has at back: " << container.back() << endl;
                            
                            return *this; 
                           
                       }
                    break;
                   
                }
                 
            //return *this;           
    
        };
        
		
        
	friend ostream& operator<< (ostream &os, QwixxRow &obj) {
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
    