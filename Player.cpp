/*
 * =================================
 * File: Player.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "Player.h"

void Player::setPlayerName(string name){
    playerName = name;
}

string Player::getPlayerName(){
    return playerName;
}

Player::Player(string name) {
    //if (name != null) //gonna assume the user will not give it non letters
        setPlayerName(name);
    //else
        //cout << "Player name must only have letters!" << endl;

}
