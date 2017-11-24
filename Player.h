/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Hussein
 *
 * Created on November 21, 2017, 3:19 PM
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
    virtual void inputBeforeRoll(RollOfDice &rollOfDice);
    virtual void inputAfterRoll(RollOfDice &rollOfDice);
    

};

#endif /* PLAYER_H */
