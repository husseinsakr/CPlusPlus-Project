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
	int numberOfFailedThrows; //number of failed throws by player
	int overallScore; //score of player, current and final
        //virtual int numberOfRows; //number of rows in Scoresheet, will be used in multidimensional arrays
        //virtual int numberOfColumns; //number of columns in Scoresheet, will be used in multidimensional arrays
        string playerName; //stores player name in Scoresheet
        //virtual long scoreSheet[][]; //scoresheet 
	
	bool score( int& RollOfDice, Colour::colour, int position = -1) = 0;
        virtual void populateScoreSheet(long &scoreSheet); //originates the first ever scoreSheet
        
        // setters and getters for numberOfRows and numberOfColumns
        void setNumberOfRows(int numberOfRows);
        int getNumberOfRows();
        void setNumberOfColumns(int numberOfColumns);
        int getNumberOfColumns();
        void setOverallScore(int score);
        int getOverallScore();
public:
	virtual ~ScoreSheet(){}
	virtual int calcTotal() = 0;
	virtual bool operator!() const = 0;
	virtual int setTotal() = 0;
	friend std::ostream& operator<< (std::ostream& os, const ScoreSheet& scoreSheet);
	virtual std::ostream& print(std::ostream& os) const = 0;
};








#endif /* SCORESHEET_H */
