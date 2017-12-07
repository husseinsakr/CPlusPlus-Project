/*
 * =================================
 * File: QwintoPlayer.cpp
 * 
 * Authors: 
 * Jordan Stanley (7432058)
 * jstan064@uottawa.ca
 * Hussein Sakr (7897706)
 * hsakr011@uottawa.ca
 * =================================
 */

#include "QwintoPlayer.h"

QwintoPlayer::QwintoPlayer(){
    qss = QwintoScoreSheet();
}

RollOfDice QwintoPlayer::inputBeforeRoll(RollOfDice &rollOfDice) {
    if (isActive){ //if player is active
        int numberOfDice = 0;
        cout << qss.playerName << " you are the active player! How many dice do you want to roll?" << endl;
        while (true) {  //asks user how many dice he wants to roll
            cin >> numberOfDice;
            if(!cin){
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
                // next, request user reinput
            }
            if (numberOfDice > 0 && numberOfDice < 4) {
                break;
            } else {
                cout << "You can only roll between 1 and 3 dice!" << endl;                
            }   
        }
        
        string diceColoursChosenByUser[numberOfDice];
        Colour diceTypeColoursChosenByUser[numberOfDice];
        string notRepetitiveColour = " ";
        
        if (numberOfDice != 3) { //asks user what dice colours he wants
            cout << "Enter the colours of the dice you would like to use!" << endl;
            
            cout << "Dice colour options are: Red, Yellow, Blue: " << endl;
            for (int i = 0; i < numberOfDice; i++) {
                cout << "Dice " << i + 1 << " colour is: ";
                cin >> diceColoursChosenByUser[i];
                transform(diceColoursChosenByUser[i].begin(),diceColoursChosenByUser[i].end(), diceColoursChosenByUser[i].begin(), ::tolower);    
                if (diceColoursChosenByUser[i] != "red" && diceColoursChosenByUser[i] != "yellow" //checks if the user pushed the right available colours
                        && diceColoursChosenByUser[i] != "blue") { 
                    i--; //decrement i to repeat call
                    cout << endl << "You have to enter either red, yellow or blue!" << endl;
                        
                } else if (i != 0){ //checks if user passes unique different dice colours
                    for (int j = 0; j < i; j++) {
                        notRepetitiveColour = diceColoursChosenByUser[j];
                        for (int k = j + 1; k <= i; k++) {
                            if(notRepetitiveColour == diceColoursChosenByUser[k]){
                                i--; //decrement i to repeat call
                                cout << endl << "Can't have two dice with the same colour!" << endl;
                            }
                        }
                    }
                }    
            }
            
            for (int n = 0; n < numberOfDice; n++) { //makes a new array to match class Colour
                if (diceColoursChosenByUser[n] == "red")
                    diceTypeColoursChosenByUser[n] = Colour::RED;
                else if (diceColoursChosenByUser[n] == "yellow")
                    diceTypeColoursChosenByUser[n] = Colour::YELLOW;
                else if (diceColoursChosenByUser[n] == "blue")
                    diceTypeColoursChosenByUser[n] = Colour::BLUE;
            }
                
        } else {
            diceTypeColoursChosenByUser[0] = Colour::RED;
            diceTypeColoursChosenByUser[1] = Colour::YELLOW;
            diceTypeColoursChosenByUser[2] = Colour::BLUE;
        }
        
        //make rollOfDice using pair than roll!
        RollOfDice diceUserWillRoll; //user will roll these dice from all dices
        for (int f = 0; f < rollOfDice.diceVec.size(); f++){  //taking only the dices the user will roll
            for (int x = 0; x < numberOfDice; x++){
                if(rollOfDice.diceVec[f].colour == diceTypeColoursChosenByUser[x]) { //making copy of dice to new RollOfDice
                    diceUserWillRoll.diceVec.push_back(rollOfDice.diceVec[f]);
                    break;
                }
            }
        }
        
        diceUserWillRoll.roll(); //user rolls the dice
        cout << diceUserWillRoll << endl; //print the roll for all users to see
        inputAfterRoll(diceUserWillRoll); //calls inputAfterRoll for everybody to score in their scoreSheet
        return diceUserWillRoll;
    }
    return rollOfDice;
}
RollOfDice QwintoPlayer::inputAfterRoll(RollOfDice &rollOfDice) {
    bool redCanBeScored = false;
    bool yellowCanBeScored = false;
    bool blueCanBeScored = false;
    bool hasBeenScored = false;
    bool rowColourChosenIsCorrect = false;
    bool indexToScoreInIsCorrect = false;
    bool userDoesntWantToScore = false;
    bool canUserScore = false;
    string askInactiveUserIfHeWantsToScore = "";
    string arrayOfScorableColours[3];
    string rowColourChosen = " ";
    Colour rowColourTypeChosen;
    int indexToScoreIn = 0;
    string leaveRow = " ";
       
    //check the dice colours that was used in the rollOfDice and what can be scored
    for (int j = 0; j < rollOfDice.diceVec.size(); j++) { 
        if(rollOfDice.diceVec[j].colour == Colour::RED){
            redCanBeScored = true;
            arrayOfScorableColours[j] = "red";
        }else if(rollOfDice.diceVec[j].colour == Colour::YELLOW){
            yellowCanBeScored = true;
            arrayOfScorableColours[j] = "yellow";
        }else if(rollOfDice.diceVec[j].colour == Colour::BLUE){
            blueCanBeScored = true;
            arrayOfScorableColours[j] = "blue";
        }
    }
    
    while (!hasBeenScored){
        
        cout << "--------------Verifying if you can even score! Please Ignore --------------"<<endl;
        for (int j = 0; j <= 10; j++) { //checks if the user can score or not
            if(redCanBeScored) {
                canUserScore = qss.validate(rollOfDice, Colour::RED, j);
                if(canUserScore){
                    break;
                }
            }
            if(yellowCanBeScored) {
                canUserScore = qss.validate(rollOfDice, Colour::YELLOW, j);
                if(canUserScore){
                    break;
                }
            }
            if(blueCanBeScored) {
                canUserScore = qss.validate(rollOfDice, Colour::BLUE, j);
                if(canUserScore){
                    break;
                }
            }
        }
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
    return rollOfDice;
}
    
