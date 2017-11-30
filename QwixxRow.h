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
    vector<T> vContainer;
    list<T> lContainer;
    string a[11] = {" 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10","11","12"};
    public:
	
	QwixxRow& operator+= (const RollOfDice& rollofdice) {
            string msg = "Your roll has more than 2 dice and can't be used to scored";
		if (rollofdice.diceVec.size() > 2 ) {
                    throw length_error(msg);
		}
                
                int rd = static_cast<int>(rollofdice);
                
                vector<T> tmpVec;
                list<T> tmpList;
                
                switch (colour) {
                    case Colour::RED: case Colour::YELLOW:
                        for (auto i : vContainer) {
                            tmpVec.push_back(i);
                        }
                        if (tmpVec.back() < rd) {
                            tmpVec.push_back(rd);
                            vContainer = tmpVec;
                        }
                    break;
                   
                    case Colour::GREEN: case Colour::BLUE:
                        for (auto i : lContainer) {
                            tmpList.emplace_back(i);
                        }
                        if (tmpList.back() > rd) {
                            tmpList.emplace_back(rd);
                            lContainer = tmpList;
                        } 
                    break;
                   
                }
                 
            return *this;           
    
        }
		
        
	friend ostream& operator<< (ostream &os, QwixxRow &obj) {
            string output; 
            output = "|";
            int y = 0;
            int entryCounter = 0;
            
            switch (colour) {
                case Colour::RED: case Colour::YELLOW:
                    entryCounter = 0;
                    y = 0;
                    for (auto x : obj.vContainer) {
                        for (y; y < 11; y++) {
                            if (obj.a[y] == to_string(x)) {
                                obj.a[y] = "XX";
                                entryCounter++;
                            }
                        }
                    }
                    for (int i = 0; i < 11; i++) {
                        output += obj.a[i] + "|";
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
                    y = 11;
                    for (auto x : obj.lContainer) {
                        for (y; y > 0; y--) {
                            if (obj.a[y] == to_string(x)) {
                                obj.a[y] = "XX";
                                entryCounter++;
                            }
                        }
                    }
                    for (int z = 11; z > 0; z--) {
                        output += obj.a[z] + "|";
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
    