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

class Player {
    int* rollDice(int numberOfRolls); //method to roll dice | need to figure out colour coded dice
    void setPlayerName(String name);
    string getPlayerName();
private:
    string playerName;




};








#endif /* PLAYER_H */
