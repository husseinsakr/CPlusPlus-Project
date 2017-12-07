/*
 * =================================
 * File: QwixxPlayer.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwixxPlayer.h"
#include "Dice.h"

QwixxPlayer::QwixxPlayer(){
    qxss = QwixxScoreSheet();
}

RollOfDice QwixxPlayer::inputBeforeRoll(RollOfDice &rollOfDice) {
    if (isActive){ //if player is active
        cout << qxss.playerName << " you are the active player! Rolling dice!" << endl;
        rollOfDice.roll(); //user rolls the dice
        cout << rollOfDice << endl; //print the roll for all users to see
        inputAfterRoll(rollOfDice); //calls inputAfterRoll for everybody to score in their scoreSheet
        return rollOfDice;
    }
    return rollOfDice;
}

RollOfDice QwixxPlayer::inputAfterRoll(RollOfDice &rollOfDice) {
    bool redCanBeScored = false;
    bool yellowCanBeScored = false;
    bool greenCanBeScored = false;
    bool blueCanBeScored = false;
    bool hasBeenScored = false;
    bool rowColourChosenIsCorrect = false;
    bool indexToScoreInIsCorrect = false;
    bool userDoesntWantToScore = false;
    bool canUserScore = false;
    bool differentWhiteDice = false;
    string askInactiveUserIfHeWantsToScore = "";
    string rowColourChosen = " ";
    Colour rowColourTypeChosen;
    int indexToScoreIn = 0;
    string leaveRow = " ";
    int arrayOfDicePostionInVector[6]; //stores in order: RED, YELLOW, GREEN, BLUE, WHITEDICE1, WHITEDICE2
       
    //check the dice colours that was used in the rollOfDice and what can be scored
    for (int j = 0; j < rollOfDice.diceVec.size(); j++) { 
        if(rollOfDice.diceVec[j].colour == Colour::RED){
            redCanBeScored = true;
            arrayOfDicePostionInVector[0] = j;
        } else if(rollOfDice.diceVec[j].colour == Colour::YELLOW){
            yellowCanBeScored = true;
            arrayOfDicePostionInVector[1] = j;
        } else if(rollOfDice.diceVec[j].colour == Colour::GREEN){
            greenCanBeScored = true;
            arrayOfDicePostionInVector[2] = j;
        } else if(rollOfDice.diceVec[j].colour == Colour::BLUE){
            blueCanBeScored = true;
            arrayOfDicePostionInVector[3] = j;
        } else if(!differentWhiteDice){
            differentWhiteDice = true;
            arrayOfDicePostionInVector[4] = j;
        } else {
            arrayOfDicePostionInVector[5] = j;
        }
    }
    
    while (!hasBeenScored){
        
        cout << "--------------Verifying if you can even score! Please Ignore --------------"<<endl;
        if(redCanBeScored) {
            RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[0]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
            RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[0]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            canUserScore = qxss.validate(rollOfDicePairedWithWhite1, Colour::RED, rollOfDice.diceVec[arrayOfDicePostionInVector[0]].face - 2) 
                    || qxss.validate(rollOfDicePairedWithWhite2, Colour::RED, rollOfDice.diceVec[arrayOfDicePostionInVector[0]].face - 2);
        }
        
        if(yellowCanBeScored) {
            RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[1]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
            RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[1]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            canUserScore = qxss.validate(rollOfDicePairedWithWhite1, Colour::YELLOW, rollOfDice.diceVec[arrayOfDicePostionInVector[1]].face - 2) 
                    || qxss.validate(rollOfDicePairedWithWhite2, Colour::YELLOW, rollOfDice.diceVec[arrayOfDicePostionInVector[1]].face - 2);
        }
        if(greenCanBeScored) {
           RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[2]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
            RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[2]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            canUserScore = qxss.validate(rollOfDicePairedWithWhite1, Colour::GREEN, rollOfDice.diceVec[arrayOfDicePostionInVector[2]].face - 2) 
                    || qxss.validate(rollOfDicePairedWithWhite2, Colour::GREEN, rollOfDice.diceVec[arrayOfDicePostionInVector[2]].face - 2);
        }
        if(blueCanBeScored) {
            RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[3]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
            RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[3]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            canUserScore = qxss.validate(rollOfDicePairedWithWhite1, Colour::BLUE, rollOfDice.diceVec[arrayOfDicePostionInVector[3]].face - 2) 
                    || qxss.validate(rollOfDicePairedWithWhite2, Colour::BLUE, rollOfDice.diceVec[arrayOfDicePostionInVector[3]].face - 2);
        }
            
        /*
        cout << "---------------------------------------------------------------------------"<<endl << endl;
        //
        if (!canUserScore && isActive){  //if user can't score increment number of failed throws and break from while loop
            cout << "Here is " << qss.playerName << "'s scoresheet!" << endl << qss
                    << "You can't score so you get a failed throw! To the next player!" << endl;
            qss.numberOfFailedThrows++;
            break;
        } else if (!canUserScore && !isActive){
            cout << "Here is " << qss.playerName << "'s scoresheet!" << endl << qss
                    << "You can't score so on to the next player!" << endl;
            break;
        }
        
        while(!rowColourChosenIsCorrect){ //asking user to choose a row colour
            cout << endl << "Here is your scoresheet!" << endl << qss;
            
            cout << "You can only score in:";
            if (redCanBeScored)
                cout << " RED";
            if (yellowCanBeScored)
                cout << " YELLOW";
            if (blueCanBeScored)
                cout << " BLUE";
            
            cout << " rows!" << endl;
            if (!isActive){
                cout << "Would you like to score at all this turn(Yes or No)?" << endl;
                cin >> askInactiveUserIfHeWantsToScore;
                transform(askInactiveUserIfHeWantsToScore.begin(),askInactiveUserIfHeWantsToScore.end(),
                        askInactiveUserIfHeWantsToScore.begin(), ::tolower);
                if(askInactiveUserIfHeWantsToScore == "no"){
                    indexToScoreInIsCorrect = true;
                    userDoesntWantToScore = true;
                    break;
                }
                    
            }
            cout << "What row colour would you like to score in?" << endl;
            cin >> rowColourChosen;
            transform(rowColourChosen.begin(),rowColourChosen.end(), rowColourChosen.begin(), ::tolower);

            if(rowColourChosen == "red" && redCanBeScored){
                rowColourTypeChosen = Colour::RED;
                rowColourChosenIsCorrect = true;
            }else if(rowColourChosen == "yellow" && yellowCanBeScored){
                rowColourTypeChosen = Colour::YELLOW;
                rowColourChosenIsCorrect = true;
            }else if(rowColourChosen == "blue" && blueCanBeScored){
                rowColourTypeChosen = Colour::BLUE;
                rowColourChosenIsCorrect = true;
            }else
                cout << "No such colour exists or you are not allowed to choose that colour!" << endl;
        }
        while (!indexToScoreInIsCorrect){  //asking user for index
            cout << "Choose what index you want to place the sum of the rolls! Range: (0-9)" << endl;
            cin >> indexToScoreIn;
            if (indexToScoreIn >= 0 && indexToScoreIn < 10)
                indexToScoreInIsCorrect = qss.score(rollOfDice, rowColourTypeChosen, indexToScoreIn);
            else
                cout << "You can't score there!" << endl;
            if(!indexToScoreInIsCorrect && (redCanBeScored + yellowCanBeScored + blueCanBeScored) > 1){
                cout << "Would you like to leave row? Type Yes or No:" << endl;
                cin >> leaveRow;
                transform(leaveRow.begin(),leaveRow.end(), leaveRow.begin(), ::tolower);
                if (leaveRow == "yes") {
                    rowColourChosenIsCorrect = false;
                    break;
                }
            }
        }
        if(indexToScoreInIsCorrect){
            if(userDoesntWantToScore)
                break;
            cout << "You have scored in index " << indexToScoreIn << "!" << endl;
            if(isActive)
                cout << "Inactive players are allowed to score now!" << endl;
            break;
        }
    }
    isActive = false; //player becomes inActive as he rolled
     */
    return rollOfDice;
}
}

