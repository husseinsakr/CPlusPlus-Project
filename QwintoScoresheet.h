/*
 * =================================
 * File: qwintoscoresheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef QWINTOSCORESHEET_H
#define QWINTOSCORESHEET_H

using std::string;
using std::ostream;
using std::vector;

class QwintoScoresheet: ScoreSheet {
public:
    void print(ostream &out);
    void score(vector<Dice> score, Colour color, int position);
    QwintoScoresheet(String playerName);
private:
    constexpr int numberOfRows = 3; 
    constexpr int numberOfColumns = 5;
    long scoreSheet[numberOfRows][numberOfColumns];
    int redScore;
    int yellowScore;
    int blueScore; 
};

#endif /* QWINTOSCORESHEET_H */

