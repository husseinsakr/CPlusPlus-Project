/*
 * =================================
 * File: QwixxPlayer.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwixxPlayer.h"

QwixxPlayer::QwixxPlayer(){
    qxss = QwixxScoreSheet();
}

RollOfDice QwixxPlayer::inputAfterRoll(RollOfDice &rollOfDice) {
    return rollOfDice;
}
RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice &rollOfDice) {
    return rollOfDice;
}
