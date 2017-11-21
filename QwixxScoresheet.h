/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QwixxScoresheet.h
 * Author: Hussein
 *
 * Created on November 21, 2017, 1:37 PM
 */

#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H

class QwixxScoreSheet: ScoreSheet {
public:
	friend std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qwixxscoresheet);
	virtual std::ostream& print(std::ostream& os) const;
	
};

#endif /* QWIXXSCORESHEET_H */

