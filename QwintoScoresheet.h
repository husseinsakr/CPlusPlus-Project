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

class QwintoScoresheet {
public:
    void print(ostream &out);
    enum class Colour{RED, YELLOW, BLUE};
    void score(vector<Dice> score, Colour color, int position);
private:
    int numberOfFailedAttempts;
    string playerName;
    int overallScore;
    int redScore;
    int yellowScore;
    int blueScore;
};

#endif /* QWINTOSCORESHEET_H */

