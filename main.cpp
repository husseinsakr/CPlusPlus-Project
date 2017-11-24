/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hussein
 *
 * Created on November 21, 2017, 3:16 PM
 */

using namespace std;

/*
 * 
 */
#include "QwintoScoreSheet.h"

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

    return 0;
}

