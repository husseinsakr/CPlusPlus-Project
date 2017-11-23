/*
 * =================================
 * File: GameDetails.h
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#ifndef GAME_DETAILS
#define GAME_DETAILS
#include <iostream>
#include <vector>
#include <list>
#include <string>


using std::string; using std::vector;


enum class Colour {RED, YELLOW, GREEN, BLUE, WHITE};

struct RandomDice{
	static constexpr int lower = 1;
	static constexpr int upper = 6;
};

struct Dice {
	const Colour colour;
	int face;
	friend std::ostream& operator<< (std::ostream& os, const Dice& dice);
	void roll();	
};


class RollOfDice {
	vector<Dice> diceVec;
public:
	operator int() const;
	void roll();
	RollOfDice pair(Dice& one, Dice& two);	
	friend std::ostream& operator<< (std::ostream& os, RollOfDice& rd);
};

class ScoreSheet {
protected:
	string namePlayer;
	int numFailed;
	int overallScore;
	
	virtual bool score( int&, RollOfDice, Colour colour, int position = -1) = 0;
public:
	virtual ~ScoreSheet(){}
	virtual int calcTotal() = 0;
	virtual bool operator!() const;
	virtual int setTotal() = 0;
	friend std::ostream& operator<< (std::ostream& os, const ScoreSheet& scoreSheet);
	virtual std::ostream& print(std::ostream& os) const = 0;
};

class QwintoScoreSheet: ScoreSheet {
public:
	friend std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qwintoscoresheet);
	virtual std::ostream& print(std::ostream& os) const; 
};

/*
class QwintoScoreSheet: protected ScoreSheet {
public:
    static constexpr int numberOfRows = 4; 
    static constexpr int numberOfColumns = 12;
    void print(ostream &out);
    QwintoScoreSheet();
    QwintoScoreSheet(string playerName);
    //long* getScoreSheet();
    void createEmptyScoreSheet(long *scoreSheet); //originates the first ever scoreSheet
private:
    long scoreSheet[numberOfRows][numberOfColumns];
    int redScore;
    int yellowScore;
    int blueScore; 
};
*/

class QwixxScoreSheet: ScoreSheet {
public:
	friend std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qwixxscoresheet);
	virtual std::ostream& print(std::ostream& os) const;

};


template <typename Colour> class QwintoRow : public QwintoScoreSheet{
    public:
        int array[numberOfColumns];
        int& operator[] (int index) const;
        bool validate(int index) const;
        friend ostream &operator<< <>(ostream &os, QwintoRow<Colour> &obj);
};

#endif /* GAME_DETAILS */