/*
 * =================================
 * File: test.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */
/*
using namespace std;

#include "QwintoPlayer.h"
#include "QwixxRow.h"

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
    /*
    cout << "D1 roll is after pairing" << D1 << endl;
    cout << "D2 roll is after pairing" << D2 << endl;
    int rollDice = static_cast<int>(rd);
    cout << "calling casting to int operator:" << endl;
    cout << rollDice << endl;
    cout << "calling insertion operator:" << endl;
    cout << rd << endl;
     
    
    //ScoreSheet *scoreSheet;
    QwintoScoreSheet scoreSheet;
    scoreSheet.numberOfFailedThrows =3;
    scoreSheet.overallScore = 10;
    scoreSheet.playerName = "Hussein";
    
    
    /*
    scoreSheet.redRow.arrayOfRolls[0] = 2;
    scoreSheet.redRow.arrayOfRolls[1] = 3;
    scoreSheet.redRow.arrayOfRolls[2] = 6;
    scoreSheet.redRow.arrayOfRolls[3] = 0;
    scoreSheet.redRow.arrayOfRolls[4] = 9;
    scoreSheet.redRow.arrayOfRolls[5] = 11;
    scoreSheet.redRow.arrayOfRolls[6] = 12;
    scoreSheet.redRow.arrayOfRolls[7] = 13;
    scoreSheet.redRow.arrayOfRolls[8] = 15;
    scoreSheet.redRow.arrayOfRolls[9] = 16;
    
    scoreSheet.yellowRow.arrayOfRolls[0] = 1;
    scoreSheet.yellowRow.arrayOfRolls[1] = 3;
    scoreSheet.yellowRow.arrayOfRolls[2] = 4;
    scoreSheet.yellowRow.arrayOfRolls[3] = 5;
    scoreSheet.yellowRow.arrayOfRolls[4] = 0;
    scoreSheet.yellowRow.arrayOfRolls[5] = 0;
    scoreSheet.yellowRow.arrayOfRolls[6] = 12;
    scoreSheet.yellowRow.arrayOfRolls[7] = 13;
    scoreSheet.yellowRow.arrayOfRolls[8] = 0;
    scoreSheet.yellowRow.arrayOfRolls[9] = 0;
    
    scoreSheet.blueRow.arrayOfRolls[0] = 1;
    scoreSheet.blueRow.arrayOfRolls[1] = 3;
    scoreSheet.blueRow.arrayOfRolls[2] = 0;
    scoreSheet.blueRow.arrayOfRolls[3] = 6;
    scoreSheet.blueRow.arrayOfRolls[4] = 0;
    scoreSheet.blueRow.arrayOfRolls[5] = 7;
    scoreSheet.blueRow.arrayOfRolls[6] = 0;
    scoreSheet.blueRow.arrayOfRolls[7] = 0;
    scoreSheet.blueRow.arrayOfRolls[8] = 10;
    scoreSheet.blueRow.arrayOfRolls[9] = 0;
    
    
    
    cout << scoreSheet;
    
    QwixxRow<vector<int>, Colour::RED> rRow;
    QwixxRow<vector<int>, Colour::YELLOW> yRow;
    QwixxRow<list<int>, Colour::GREEN> gRow;
    QwixxRow<list<int>, Colour::BLUE> bRow;
    
    
    rRow += rd;
    rd.roll();
    rRow += rd;
    rd.roll();
    rRow += rd;
    rd.roll();
    rRow += rd;
    rd.roll();
    rRow += rd;
    
    cout << "        ------------------------------------" << endl;
    cout << "Red     " << rRow;
    cout << endl;
    cout << "        ------------------------------------" << endl;
    cout << "Yellow  " << yRow;
    cout << endl;
    cout << "        ------------------------------------" << endl;
    cout << "Green   " << gRow;
    cout << endl;
    cout << "        ------------------------------------" << endl;
    cout << "Blue    " << bRow;
    cout << endl;
    cout << "        ------------------------------------" << endl;
    
    
    QwintoPlayer player1;
    player1.qss = scoreSheet;
    player1.isActive = true;
    player1.inputAfterRoll(rd);
    cout << player1.qss;

    return 0;
}

*/