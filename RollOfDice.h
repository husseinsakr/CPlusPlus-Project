/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RollOfDice.h
 * Author: Hussein
 *
 * Created on November 23, 2017, 6:57 PM
 */

#ifndef ROLLOFDICE_H
#define ROLLOFDICE_H

#include "Dice.h"

class RollOfDice {
	vector<Dice> diceVec;
public:
	operator int() const;
	void roll();
	RollOfDice pair(Dice& one, Dice& two);	
	friend ostream &operator<< (ostream& os, RollOfDice &rd);
};




#endif /* ROLLOFDICE_H */
