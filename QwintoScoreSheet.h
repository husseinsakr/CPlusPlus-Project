/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QwintoScoreSheet.h
 * Author: Hussein
 *
 * Created on November 21, 2017, 5:37 PM
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H

#include "QwintoRow.h"
#include "ScoreSheet.h"


class QwintoScoreSheet: protected ScoreSheet {
public:
    QwintoRow<Colour::RED> redRow;
    QwintoRow<Colour::BLUE> blueRow;
    QwintoRow<Colour::YELLOW> yellowRow;
private:
    long scoreSheet[numberOfRows][numberOfColumns];
    int redScore;
    int yellowScore;
    int blueScore; 
};



#endif /* QWINTOSCORESHEET_H */
