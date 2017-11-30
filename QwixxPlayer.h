/*
 * =================================
 * File: QwixxPlayer.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWIXXPLAYER_H
#define QWIXXPLAYER_H

#include "Player.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer : public Player {
    QwixxScoreSheet qxss;
    void inputAfterRoll(RollOfDice &rollOfDice);
    void inputBeforeRoll(RollOfDice &rollOfDice);
};

#endif /* QWIXXPLAYER_H */
