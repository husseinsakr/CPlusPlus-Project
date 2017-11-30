/*
 * =================================
 * File: QwintoPlayer.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */


#ifndef QWINTOPLAYER_H
#define QWINTOPLAYER_H

#include "Player.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player {
	QwintoScoreSheet qss;
        
public:
    void inputBeforeRoll(RollOfDice &rollOfDice);
    void inputAfterRoll(RollOfDice &rollOfDice);
    
};

#endif /* QWINTOPLAYER_H */
