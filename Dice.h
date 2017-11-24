/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Hussein
 *
 * Created on November 21, 2017, 3:58 PM
 */

#ifndef GAME_H
#define GAME_H

#include "RandomDice.h"
#include "Colour.h"
#include "AllIncludes.h"

struct Dice {
	const Colour colour;
	int face;
	friend ostream &operator<< (ostream &os, const Dice &dice);
	void roll();	
};



#endif /* GAME_H */
