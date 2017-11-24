/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Hussein
 * 
 * Created on November 21, 2017, 3:58 PM
 */

#include "Dice.h"

//Function implementation for Dice class
ostream &operator<< (ostream &os, const Dice &dice) {  //output operator overloaded
	os << dice.face;
	return os;
}
void Dice::roll() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(RandomDice::lower, RandomDice::upper);
	int tmp = dis(gen);
	this->face = tmp;
}

