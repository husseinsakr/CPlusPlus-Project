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

#include "RollOfDice.h"

//abstract parent class
class Player {
    
public:
    //instance variables
    bool isActive = false; //indicates if this player is the active player or not
    //methods
    //these functions will behave differently if the player is active or not
    virtual RollOfDice inputBeforeRoll(RollOfDice &rollOfDice) = 0;
    virtual RollOfDice inputAfterRoll(RollOfDice &rollOfDice) = 0;
   
};

#endif /* PLAYER_H */
