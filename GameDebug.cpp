/*
 * =================================
 * File: GameDebug.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */
 
 #include <iostream>
 #include "GameDetails.h"
 
 using std::cout; using std::endl;
 
 int main() {
	 Dice D1 = {Colour::BLUE, RandomDice::lower};
	 Dice D2 = {Colour::RED, RandomDice::lower};
	 
	
	//Testing Dice::roll()	
	 D1.roll();
	 cout << "D1 roll is: " << D1 << endl;
	 D1.roll();
	 cout << "D1 roll is: " << D1 << endl;
	 
	 D2.roll();
	 cout << "D2 roll is: " << D2 << endl;
	 D2.roll();
	 cout << "D2 roll is: " << D2 << endl;
	 
	 
	 //testing rollofdice 
	 RollOfDice rd;
	 rd.pair(D1, D2);
	 rd.roll();
	 int rollDice = static_cast<int>(rd);
	 cout << "calling casting to int operator:" << endl;
	 cout << rollDice << endl;
	 cout << "calling insertion operator:" << endl;
	 cout << rd << endl;
	
 }