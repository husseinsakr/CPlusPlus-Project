/*
 * =================================
 * File: main.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
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
    //D1.roll();
    //cout << "D1 roll is: " << D1 << endl;
    //D1.roll();
    //cout << "D1 roll is: " << D1 << endl;
	 
    //D2.roll();
    //cout << "D2 roll is: " << D2 << endl;
    //D2.roll();
    //cout << "D2 roll is: " << D2 << endl;
	 
    //testing rollofdice 
    RollOfDice rd;
    rd.pair(D1, D2);
    rd.roll();
    cout << "D1 roll is after pairing" << D1 << endl;
    cout << "D2 roll is after pairing" << D2 << endl;
    int rollDice = static_cast<int>(rd);
    cout << "calling casting to int operator:" << endl;
    cout << rollDice << endl;
    cout << "calling insertion operator:" << endl;
    cout << rd << endl;
    
    QwintoRow<Colour::RED> row;
    
    //row[2] = rd;
    //QwintoScoreSheet scoreSheet = {0, 0, "Hussein"};
    //QwintoScoreSheet qwintoScoreSheet;

    return 0;
}

