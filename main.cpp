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

#include "QwintoPlayer.h"
#include "QwixxPlayer.h"

using namespace std;

int main() {
    RollOfDice dice;
    RollOfDice diceRolled;
    string versionOfGame = "";
    int numberOfPlayers = 0;
    vector<QwintoPlayer> qwintoPlayers;
    vector<QwixxPlayer> qwixxPlayers;
    bool userChoseVersionOfGame = false;
    bool userChoseNumberOfPlayers = false;
    bool userNamedThePlayers = false;
    int activeUser = 0;
    while (true){ //asking user to choose game version, number of players and name of players
        if (!userChoseVersionOfGame){ //checks if the user gave the correct input, loops if he/she didnt
            cout << "What version of the game would you like to play? (Qwinto or Qwixx)" << endl;
            cin >> versionOfGame;
            transform(versionOfGame.begin(),versionOfGame.end(), versionOfGame.begin(), ::tolower);
            if (versionOfGame != "qwinto" && versionOfGame != "qwixx") {
                cout << "Incorrect version! Please choose a right one!" << endl;
            } else {
                userChoseVersionOfGame = true;
                if (versionOfGame == "qwinto"){ //create red, yellow and blue dice
                    dice = RollOfDice();
                    Dice redDice(Colour::RED, 6);
                    Dice yellowDice(Colour::YELLOW, 6);
                    Dice blueDice(Colour::BLUE, 6);
                    dice.diceVec.push_back(redDice);
                    dice.diceVec.push_back(yellowDice);
                    dice.diceVec.push_back(blueDice);
                } else { //create red, yellow, green, blue and white dice
                    dice = RollOfDice();
                    Dice redDice(Colour::RED, 6);
                    Dice yellowDice(Colour::YELLOW, 6);
                    Dice blueDice(Colour::BLUE, 6);
                    Dice greenDice(Colour::GREEN, 6);
                    Dice whiteDice(Colour::WHITE, 6);
                    dice.diceVec.push_back(redDice);
                    dice.diceVec.push_back(yellowDice);
                    dice.diceVec.push_back(blueDice);
                    dice.diceVec.push_back(greenDice);
                    dice.diceVec.push_back(whiteDice);
                }  
            }
        } else if (!userChoseNumberOfPlayers) { //checks if the user gave the correct input, loops if he/she didnt
            cout << "How many players are going to play?(2-5)" << endl;
            cin >> numberOfPlayers;
            if (numberOfPlayers == 0 || numberOfPlayers < 2 || numberOfPlayers > 5) {
                cout << "You have to have between 2 to 5 players!" << endl;
            } else {
                for(int i = 0; i < numberOfPlayers; i++) {
                    qwintoPlayers.push_back(QwintoPlayer());
                    qwixxPlayers.push_back(QwixxPlayer());
                }
                userChoseNumberOfPlayers = true;
            }
        } else if (!userNamedThePlayers) { //checks if the user gave the correct input, loops if he/she didnt
            cout << "Name your players!" << endl;
            if (versionOfGame == "qwinto"){
                for (int i = 0; i < numberOfPlayers; i++) {
                    cout << "Player " << i + 1 << ": ";
                    cin >> qwintoPlayers[i].qss.playerName;
                }
                break;
            } else {
                for (int i = 0; i < numberOfPlayers; i++) {
                    cout << "Player " << i + 1 << ": ";
                    cin >> qwixxPlayers[i].qxss.playerName;
                }
                break;
            }
        }
    }
     
    if(versionOfGame == "qwinto"){
        while (true){
            
            for(int i = 0; i < numberOfPlayers; i++){ //loop to check if game is over
                if(!(qwintoPlayers[i].qss)){ //if game is over break loop
                    cout << "Game is over!" << endl;
                    break;
                }
            }
            qwintoPlayers[activeUser++].isActive = true; //sets player to active
            diceRolled = qwintoPlayers[activeUser - 1].inputBeforeRoll(dice); //getting input from active user
            for (int j = 0; j < numberOfPlayers; j++){ //looping over nonactive users after roll to score in their scoresheet if they want
                if(j != (activeUser - 1)){
                    qwintoPlayers[j].inputAfterRoll(diceRolled);
                }
            }
        }
        
        int maxScore = 0, positionOfWinnderInArray;
        for (int k = 0; k < numberOfPlayers; k++){
            qwintoPlayers[k].qss.setTotal();
            if (maxScore < qwintoPlayers[k].qss.overallScore){
                maxScore = qwintoPlayers[k].qss.overallScore;
                positionOfWinnderInArray = k;
            }
            cout << qwintoPlayers[k].qss;
        }
        
        cout << "Congratulations " << qwintoPlayers[positionOfWinnderInArray].qss.playerName
                << "! You are the winner of this game!" << endl; 
    } else {
        while (true){
            
            for(int i = 0; i < numberOfPlayers; i++){ //loop to check if game is over
                if(!(qwixxPlayers[i].qxss)){ //if game is over break loop
                    cout << "Game is over!" << endl;
                    break;
                }
            }
            qwixxPlayers[activeUser++].isActive = true; //sets player to active
            diceRolled = qwixxPlayers[activeUser - 1].inputBeforeRoll(dice); //getting input from active user
            for (int j = 0; j < numberOfPlayers; j++){ //looping over nonactive users after roll to score in their scoresheet if they want
                if(j != (activeUser - 1)){
                    qwixxPlayers[j].inputAfterRoll(diceRolled);
                }
            }
        }
        
        int maxScore = 0, positionOfWinnderInArray;
        for (int k = 0; k < numberOfPlayers; k++){
            qwixxPlayers[k].qxss.setTotal();
            if (maxScore < qwixxPlayers[k].qxss.overallScore){
                maxScore = qwixxPlayers[k].qxss.overallScore;
                positionOfWinnderInArray = k;
            }
            cout << qwixxPlayers[k].qxss;
        }
        
        cout << "Congratulations " << qwixxPlayers[positionOfWinnderInArray].qxss.playerName
                << "! You are the winner of this game!" << endl; 
    }
    
    
    
    return 0;
}

