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
    string versionOfGame = "";
    int numberOfPlayers = 0;
    QwintoPlayer *qwintoPlayers;
    QwixxPlayer *qwixxPlayers;
    bool userChoseVersionOfGame = false;
    bool userChoseNumberOfPlayers = false;
    bool userNamedThePlayers = false;
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
                if(versionOfGame == "qwinto"){
                    qwintoPlayers = new QwintoPlayer[numberOfPlayers];
                } else {
                    qwixxPlayers = new QwixxPlayer[numberOfPlayers];
                }
                userChoseNumberOfPlayers = true;
            }
        } else if (!userNamedThePlayers) { //checks if the user gave the correct input, loops if he/she didnt
            cout << "Name your players!" << endl;
            if (versionOfGame == "qwinto"){
                for (int i = 0; i < numberOfPlayers; i++) {
                    cout << "Player " << i + 1 << ": ";
                    cin >> qwintoPlayers->qss.playerName;
                    qwintoPlayers++;
                }
                break;
            } else {
                for (int i = 0; i < numberOfPlayers; i++) {
                    cout << "Player " << i + 1 << ": ";
                    cin >> qwixxPlayers->qxss.playerName;
                    qwintoPlayers++;
                }
                break;
            }
        }
    }
    
    cout << dice;
    
    
    return 0;
}

