/*
 * =================================
 * File: Player.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

using std::cout; 
using std::endl;
using std::string;

class Player {
    int* rollDice(int numberOfRolls); //method to roll dice | need to figure out colour coded dice
    void setPlayerName(string name);
    string getPlayerName();
    Player(string name);
private:
    string playerName;
};








#endif /* PLAYER_H */
