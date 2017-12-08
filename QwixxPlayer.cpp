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
    bool redCanBeScored = false , yellowCanBeScored = false, greenCanBeScored = false, blueCanBeScored = false;
    int hasBeenScored = 0;
    bool rowColourChosenIsCorrect = false;
    bool indexToScoreInIsCorrect = false;
    bool userDoesntWantToScore = false;
    bool userChoseWhatToScore = false;
    bool canUserScoreColourWithWhite1 = false;
    bool canUserScoreColourWithWhite2 = false;
    bool canUserScoreWhiteAndWhite = false;
    bool canUserScore = false;
    bool differentWhiteDice = false;
    bool verificationPassed = false;
    bool userScoredColourAndWhite = false;
    bool userScoredWhiteCombination = false;
    RollOfDice rollOfDiceToScore;
    int userChoseToScoreWith = 0;
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
    
    while (hasBeenScored < 2){
        
        if(!verificationPassed){
            cout << "--------------Verifying if you can even score! Please Ignore --------------"<<endl;
            RollOfDice pairOfWhiteDice = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[4]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            if(redCanBeScored) {
                RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[0]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
                RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[0]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
                canUserScoreColourWithWhite1 = qxss.validate(rollOfDicePairedWithWhite1, Colour::RED, rollOfDicePairedWithWhite1 - 2); 
                canUserScoreColourWithWhite2 = qxss.validate(rollOfDicePairedWithWhite2, Colour::RED, rollOfDicePairedWithWhite2 - 2);
                canUserScoreWhiteAndWhite = qxss.validate(pairOfWhiteDice, Colour::RED, pairOfWhiteDice - 2);
            }

            if(yellowCanBeScored && (!canUserScoreColourWithWhite1 || !canUserScoreColourWithWhite2) ) {
                RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[1]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
                RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[1]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
                canUserScoreColourWithWhite1 = qxss.validate(rollOfDicePairedWithWhite1, Colour::YELLOW, rollOfDicePairedWithWhite1 - 2); 
                canUserScoreColourWithWhite2 = qxss.validate(rollOfDicePairedWithWhite2, Colour::YELLOW, rollOfDicePairedWithWhite2 - 2);
                canUserScoreWhiteAndWhite = qxss.validate(pairOfWhiteDice, Colour::YELLOW, pairOfWhiteDice - 2);
            }
            if(greenCanBeScored && !canUserScoreColourWithWhite1 || !canUserScoreColourWithWhite2) {
               RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[2]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
                RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[2]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
                canUserScoreColourWithWhite1 = qxss.validate(rollOfDicePairedWithWhite1, Colour::GREEN, rollOfDicePairedWithWhite1 - 2); 
                canUserScoreColourWithWhite2 = qxss.validate(rollOfDicePairedWithWhite2, Colour::GREEN, rollOfDicePairedWithWhite2 - 2);
                canUserScoreWhiteAndWhite = qxss.validate(pairOfWhiteDice, Colour::GREEN, pairOfWhiteDice - 2);
            }
            if(blueCanBeScored && !canUserScoreColourWithWhite1 || !canUserScoreColourWithWhite2) {
                RollOfDice rollOfDicePairedWithWhite1 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[3]], rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
                RollOfDice rollOfDicePairedWithWhite2 = rollOfDice.pair(rollOfDice.diceVec[arrayOfDicePostionInVector[3]], rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
                canUserScoreColourWithWhite1 = qxss.validate(rollOfDicePairedWithWhite1, Colour::BLUE, rollOfDicePairedWithWhite1 - 2); 
                canUserScoreColourWithWhite2 = qxss.validate(rollOfDicePairedWithWhite2, Colour::BLUE, rollOfDicePairedWithWhite2 - 2);
                canUserScoreWhiteAndWhite = qxss.validate(pairOfWhiteDice, Colour::BLUE, pairOfWhiteDice - 2);
            }
            canUserScore = canUserScoreWhiteAndWhite + canUserScoreColourWithWhite1 + canUserScoreColourWithWhite2;
            cout << "---------------------------------------------------------------------------"<<endl << endl;
            //
            if (!canUserScore && isActive){  //if user can't score increment number of failed throws and break from while loop
                cout << "Here is " << qxss.playerName << "'s scoresheet!" << endl << qxss
                        << "You can't score so you get a failed throw! To the next player!" << endl;
                qxss.numberOfFailedThrows++;
                break;
            } else if (!canUserScore && !isActive){
                cout << "Here is " << qxss.playerName << "'s scoresheet!" << endl << qxss
                        << "You can't score so on to the next player!" << endl;
                break;
            } else {
                verificationPassed = true;
                cout << endl << "Here is your scoresheet!" << endl << qxss;
            }
        }
        while(!userChoseWhatToScore){
            if (!isActive){
                cout << "Would you like to score at all this turn(Yes or No)?" << endl;
                cin >> askInactiveUserIfHeWantsToScore;
                transform(askInactiveUserIfHeWantsToScore.begin(),askInactiveUserIfHeWantsToScore.end(),
                        askInactiveUserIfHeWantsToScore.begin(), ::tolower);
                if(askInactiveUserIfHeWantsToScore == "no"){
                    userDoesntWantToScore = true;
                    break;
                }
            } 
            cout << "You can only score with:"<<endl;
            if(!userScoredColourAndWhite && (canUserScoreColourWithWhite1 || canUserScoreColourWithWhite2))
                cout << "\t1)A combination of a white and coloured dice" << endl;
            if(canUserScoreWhiteAndWhite && !userScoredWhiteCombination)
                cout << "\t2)A combination of the white dice" << endl;
            cout << "Type their respective numbers(1,2): ";
            cin >> userChoseToScoreWith;
            if(!cin){
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
                // next, request user reinput
            }
            if (userChoseToScoreWith > 0 && userChoseToScoreWith < 3){
                
                if(userChoseToScoreWith == 1 && !userScoredColourAndWhite){
                    userChoseWhatToScore = true;
                }else if(userChoseToScoreWith == 2 && !userScoredWhiteCombination){
                    userChoseWhatToScore = true;
                }
            } else { 
                cout << "You can only choose the NUMBERS, type 1 or 2!" << endl;
            }
        }
        if (userDoesntWantToScore)
            break;
        if (userChoseToScoreWith == 1 && userChoseWhatToScore){ //if the user chose to score with a combination of white and a colour dice get the dice he wants to use
            cout << "Choose which white dice you want to use in the combination! Type First or Second!" << endl;
            string whiteDiceChosen = "";
            string colouredDiceChosen = "";
            int whiteDice;
            int colouredDice;
            
            while(true){ //asks user to choose which white dice to use in scoring the dice   
                cin >> whiteDiceChosen;
                transform(whiteDiceChosen.begin(),whiteDiceChosen.end(), whiteDiceChosen.begin(), ::tolower);
                if(whiteDiceChosen == "first"){
                    if(!canUserScoreColourWithWhite1)
                        cout << "Can't use this white dice!" << endl;
                    else{
                        whiteDice = 4;
                        break;
                    }
                } else if(whiteDiceChosen == "second"){
                    if(!canUserScoreColourWithWhite2)
                        cout << "Can't use this white dice!" << endl;
                    else {
                        whiteDice = 5;
                        break;
                    }
                } else {
                    cout << "No such dice exist! Please choose first or second!" << endl;
                }
            }
            cout << "Choose which coloured dice you want to use in the combination! Type Red, Yellow, Green, or Blue!" << endl;
            while(true){
                cin >> colouredDiceChosen;
                transform(colouredDiceChosen.begin(),colouredDiceChosen.end(), colouredDiceChosen.begin(), ::tolower);
                if(colouredDiceChosen == "red"){
                    colouredDice = 0;
                    rowColourChosenIsCorrect = true;
                    break;
                } else if (colouredDiceChosen == "yellow"){
                    colouredDice = 1;
                    rowColourChosenIsCorrect = true;
                    break;
                } else if (colouredDiceChosen == "green"){
                    colouredDice = 2;
                    rowColourChosenIsCorrect = true;
                    break;
                } else if (colouredDiceChosen == "blue"){
                    colouredDice = 3;
                    rowColourChosenIsCorrect = true;
                    break;
                } else {
                    cout << "Choose which coloured dice you want to use in the combination! Type Red, Yellow, Green, or Blue!" << endl;
                }
            }
            rollOfDiceToScore.diceVec.push_back(rollOfDice.diceVec[arrayOfDicePostionInVector[whiteDice]]);
            rollOfDiceToScore.diceVec.push_back(rollOfDice.diceVec[arrayOfDicePostionInVector[colouredDice]]);
            rowColourTypeChosen = rollOfDice.diceVec[arrayOfDicePostionInVector[colouredDice]].colour;
        } else {
            rollOfDiceToScore.diceVec.push_back(rollOfDice.diceVec[arrayOfDicePostionInVector[4]]);
            rollOfDiceToScore.diceVec.push_back(rollOfDice.diceVec[arrayOfDicePostionInVector[5]]);
            cout << "You have to score " << rollOfDiceToScore.diceVec[0].face + rollOfDiceToScore.diceVec[1].face << " in a coloured row!" << endl;
        }
        while(!rowColourChosenIsCorrect){ //asking user to choose a row colour
            cout << "You can only score in:";
            if (redCanBeScored)
                cout << " RED";
            if (yellowCanBeScored)
                cout << " YELLOW";
            if (greenCanBeScored)
                cout << " GREEN";
            if (blueCanBeScored)
                cout << " BLUE";
            
            cout << " rows!" << endl;
            cout << "What row colour would you like to score in?" << endl;
            cin >> rowColourChosen;
            transform(rowColourChosen.begin(),rowColourChosen.end(), rowColourChosen.begin(), ::tolower);

            if(rowColourChosen == "red" && redCanBeScored){
                rowColourTypeChosen = Colour::RED;
                rowColourChosenIsCorrect = true;
            }else if(rowColourChosen == "yellow" && yellowCanBeScored){
                rowColourTypeChosen = Colour::YELLOW;
                rowColourChosenIsCorrect = true;
            }else if(rowColourChosen == "green" && greenCanBeScored){
                rowColourTypeChosen = Colour::GREEN;
                rowColourChosenIsCorrect = true;
            }else if(rowColourChosen == "blue" && blueCanBeScored){
                rowColourTypeChosen = Colour::BLUE;
                rowColourChosenIsCorrect = true;
            }else{
                cout << "No such colour exists or you are not allowed to choose that colour!" << endl;
                if ((!userScoredColourAndWhite && (canUserScoreColourWithWhite1 || canUserScoreColourWithWhite2)) && (canUserScoreWhiteAndWhite && !userScoredWhiteCombination)){
                    string leaveThisOption = "";
                    cout << "Do you want to get out of this option of scoring? (type Yes or No)" << endl;
                    cin >> leaveThisOption;
                    transform(leaveThisOption.begin(),leaveThisOption.end(), leaveThisOption.begin(), ::tolower);
                    if (leaveThisOption == "yes"){
                        userChoseWhatToScore = false;
                        rowColourChosenIsCorrect = false;
                        indexToScoreInIsCorrect = false;
                        break;
                    }
                }
            }
        }
        
        while (!indexToScoreInIsCorrect && userChoseWhatToScore){  //asking user for index
            indexToScoreInIsCorrect = qxss.score(rollOfDiceToScore, rowColourTypeChosen, rollOfDiceToScore - 2);
            if(!indexToScoreInIsCorrect){
                cout << "You couldn't score here! Leaving row!" << endl;
                rowColourChosenIsCorrect = false;
                break;
            } else {
                string activeWantsToScoreAgain = "";
                hasBeenScored++;
                cout << "You scored! " << endl;
                if(hasBeenScored < 2 && isActive){
                    cout << "You have the option to score again(Yes or No)?" << endl;
                    cin >> activeWantsToScoreAgain;
                    transform(leaveRow.begin(),leaveRow.end(), leaveRow.begin(), ::tolower);
                    if (activeWantsToScoreAgain == "yes") {
                        userChoseWhatToScore = false;
                        rowColourChosenIsCorrect = false;
                        indexToScoreInIsCorrect = false;
                        verificationPassed = false;
                        break;
                    } else {
                        userDoesntWantToScore = true;
                        break;
                    }
                } else if(!isActive){
                    userDoesntWantToScore = true;
                    break;
                }
            }
        }
        
        rollOfDiceToScore.diceVec.pop_back();
        rollOfDiceToScore.diceVec.pop_back();
        
        if (userDoesntWantToScore)
            break;
        
        if(hasBeenScored == 2){
            if(isActive)
                cout << "Inactive players are allowed to score now!" << endl;
            break;
        }
    }
    isActive = false; //player becomes inActive as he rolled
    return rollOfDice;
}


