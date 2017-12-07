/*
 * =================================
 * File: QwixxScoreSheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWIXXSCORESHEET_H
#define QWIXXSCORESHEET_H

#include "QwixxRow.h"
#include "ScoreSheet.h"


class QwixxScoreSheet : public ScoreSheet {
    
public:
    QwixxRow<vector<int>, Colour::RED> redRow;
    QwixxRow<vector<int>, Colour::YELLOW> yellowRow;
    QwixxRow<list<int>, Colour::GREEN> greenRow;
    QwixxRow<list<int>, Colour::BLUE> blueRow;
    
    
    bool validate(RollOfDice &rollOfDice, Colour colour, int position);
    
    int calcTotal();
    
    
    bool score(RollOfDice &rollOfDice, Colour colour, int position);
    bool operator! ();
    ostream& doprint(ostream& os) const {
        os << "        ------------------------------------" << endl;
        os << "Red     " << redRow;
        os << endl;
        os << "        ------------------------------------" << endl;
        os << "Yellow  " << yellowRow;
        os << endl;
        os << "        ------------------------------------" << endl;
        os << "Green   " << greenRow;
        os << endl;
        os << "        ------------------------------------" << endl;
        os << "Blue    " << blueRow;
        os << endl;
        os << "        ------------------------------------" << endl;
        return os;
    }
     
    //functions
    friend ostream& operator<< (ostream &os, const QwixxScoreSheet &aQwixxScoreSheet) {
        return aQwixxScoreSheet.doprint(os);
    }
};

#endif /* QWIXXSCORESHEET_H */
