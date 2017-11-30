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
    T<int> container;
    public:
	
	int& operator+= (*this, const RollOfDice& rollofdice) {
		string msg = "Your roll has more than 2 dice and can't be used to scored";
		if (rollofdice.diceVec.size() > 2 ) {
                    throw length_error(msg);
		}
                int rd = static_cast<int>(rollofdice);
                switch (colour) {
                    case Colour::RED: case Colour::YELLOW:
                        vector<int> tmp;
                        for (auto i : container) {
                            tmp.push_back(i);
                        }
                        if (tmp.back() < rd) {
                            tmp.push_back(rd);
                            this->container = tmp;
                        }
                    break;
                    
                    case Colour::GREEN: case Colour::BLUE:
                        list<int> tmp;
                        for (auto i : container) {
                            tmp.emplace_back(i);
                        }
                        if (tmp.back() > rd) {
                            tmp.emplace_back(rd);
                            this->container = tmp;
                        } 
                    break;
                    
                    return *this;
                }
                
                
                
	}
	friend ostream& operator<< (ostream &os, const QwixxRow &obj) {
            string output; 
            string tmp;
            output = "|";
            int y = 2;
            int entryCounter = 0;
            
            switch (colour) {
                case Colour::RED:
                    entryCounter = 0;
                    y = 2;
                    for (int i : obj.container) {
                       if (i == 0 && y <= 9) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                       } 
                       if (i == 0 && y > 9) {
                           tmp = to_string(y) + "|"; 
                           output += tmp;
                       }
                       if (i != 0) {
                           entryCounter++;
                           tmp = "XX|";
                           output += tmp;
                       }
                       y++;
                    }
                    if (entryCounter == 5) {
                        tmp = " L";
                        output += tmp;
                    }
                    if (entryCounter != 5) {
                        tmp = " U";
                        output += tmp;
                    }
                    os << output;
                break;
                
                case Colour::YELLOW:
                    entryCounter = 0;
                    y = 2;
                    for (int i : obj.container) {
                       if (i == 0 && y <= 9) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                       } 
                       if (i == 0 && y > 9) {
                           tmp = to_string(y) + "|"; 
                           output += tmp;
                       }
                       if (i != 0) {
                           entryCounter++;
                           tmp = "XX|";
                           output += tmp;
                       }
                       y++;
                    }
                    if (entryCounter == 5) {
                        tmp = " L";
                        output += tmp;
                    }
                    if (entryCounter != 5) {
                        tmp = " U";
                        output += tmp;
                    }
                    os << output;
                break;
                
                case Colour::GREEN:
                    entryCounter = 0;
                    y = 12;
                    for (int i : obj.container) {
                       if (i == 0 && y <= 9) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                       } 
                       if (i == 0 && y > 9) {
                           tmp = to_string(y) + "|"; 
                           output += tmp;
                       }
                       if (i != 0) {
                           entryCounter++;
                           tmp = "XX|";
                           output += tmp;
                       }
                       y--;
                    }
                    if (entryCounter == 5) {
                        tmp = " L";
                        output += tmp;
                    }
                    if (entryCounter != 5) {
                        tmp = " U";
                        output += tmp;
                    }
                    os << output;
                break;
                
                case Colour::BLUE:
                    entryCounter = 0;
                    y = 12;
                    for (int i : obj.container) {
                       if (i == 0 && y <= 9) {
                           tmp = " " + to_string(y) + "|";
                           output += tmp;
                       } 
                       if (i == 0 && y > 9) {
                           tmp = to_string(y) + "|"; 
                           output += tmp;
                       }
                       if (i != 0) {
                           entryCounter++;
                           tmp = "XX|";
                           output += tmp;
                       }
                       y--;
                    }
                    if (entryCounter == 5) {
                        tmp = " L";
                        output += tmp;
                    }
                    if (entryCounter != 5) {
                        tmp = " U";
                        output += tmp;
                    }
                    os << output;
                break;                            
             return os;
            }
        }
    };
#endif/* QWIXXROW_H */
