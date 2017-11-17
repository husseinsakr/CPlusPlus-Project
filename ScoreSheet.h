/*
 * =================================
 * File: ScoreSheet.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef SCORESHEET_H
#define SCORESHEET_H

class ScoreSheet {
protected:
	string namePlayer;
	int numFailed;
	int overallScore;
        int numberOfRows;
        int numberOfColumns;
	
	bool score( int&, RollOfDice, Colour::colour, int position = -1) = 0;
        void populateScoreSheet(long scoreSheet[][]);
        void setNumberOfRows(int numberOfRows);
        int getNumberOfRows();
        void setNumberOfColumns(int numberOfColumns);
        int getNumberOfColumns();
public:
	virtual ~ScoreSheet(){}
	int calcTotal() = 0;
	virtual bool operator!() const = 0;
	virtual int setTotal() = 0;
	friend ostream& operator<< (ostream& os, const ScoreSheet& scoreSheet) = 0;
	virtual ostream& print(ostream& os) const = 0;
};








#endif /* SCORESHEET_H */
