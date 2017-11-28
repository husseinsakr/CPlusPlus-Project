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
 
#include "AllInclude.h"
#include "RollOfDice.h"
 
template <Class T, Colour colour>
class QwixxRow {
	T a[10];
public:
	
	T& operator+= (const RollOfDice& rollofdice) {
		string msg = "Your roll has more than 2 dice and can't be scored";
		if (rollofdice.diceVec.size() > 2 ) {
			throw length_error(msg);
		}
	}
	friend ostream& operator<< (ostream &os, const QwixxRow &obj) {
		
	}