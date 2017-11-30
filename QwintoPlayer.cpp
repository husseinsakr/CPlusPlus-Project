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

void QwintoPlayer::inputBeforeRoll(RollOfDice &rollOfDice) {
    if (isActive){ //if player is active
        int numberOfDice = 0;
        cout << "How many dice do you want to roll?" << endl;
        while (true) {  //asks user how many dice he wants to roll
            cin >> numberOfDice;
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
            cout << "Enter the colours of the dice you would like to use" << endl;
            
            cout << "Dice colours: " << endl;
            for (int i = 1; i <= numberOfDice; i++) {
                cout << "Dice " << i << " colour is: ";
                cin >> diceColoursChosenByUser[i - 1];
                    
                if (diceColoursChosenByUser[i - 1] != "red" && diceColoursChosenByUser[i - 1] != "yellow" //checks if the user pushed the right available colours
                        && diceColoursChosenByUser[i - 1] != "blue") {  //need to figure out how to make strings lowercase
                    i--; //decrement i to repeat call
                    cout << endl << "You have to enter either red, yellow or blue!" << endl;
                        
                } else if (i != 1){ //checks if user passes unique different dice colours
                    for (int j = 0; j < i - 1; j++) {
                        notRepetitiveColour = diceColoursChosenByUser[j];
                        for (int k = j + 1; k < i; k++) {
                            if(notRepetitiveColour != diceColoursChosenByUser[k]){
                                i--; //decrement i to repeat call
                                cout << endl << "Can't have two dice with the same colour!" << endl;
                            }
                        }
                    }
                }    
            }
            
            for (int n = 0; n < sizeof(diceColoursChosenByUser); n++) { //makes a new array to match class Colour
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
            for (int x = 0; x < sizeof(diceTypeColoursChosenByUser); x++){
                if(rollOfDice.diceVec[f].colour == diceTypeColoursChosenByUser[x]) { //making copy of dice to new RollOfDice
                    diceUserWillRoll.diceVec.push_back(rollOfDice.diceVec[f]);
                }
            }
        }
        
        diceUserWillRoll.roll(); //user rolls the dice
        inputAfterRoll(diceUserWillRoll); //calls inputAfterRoll for everybody to score in their scoreSheet
    }
}
void QwintoPlayer::inputAfterRoll(RollOfDice &rollOfDice) {
    bool redCanBeScored = false;
    bool yellowCanBeScored = false;
    bool blueCanBeScored = false;
    bool hasBeenScored = false;
    bool rowColourChosenIsCorrect = false;
    bool canUserScore = false;
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
        if (!canUserScore){  //if user can't score increment number of failed throws and break from while loop
            qss.numberOfFailedThrows++;
            break;
        }
        
        while(!rowColourChosenIsCorrect){ //user asked to choose a row colour
            cout << "You can only score in:";
            if (redCanBeScored)
                cout << " RED";
            if (yellowCanBeScored)
                cout << " YELLOW";
            if (blueCanBeScored)
                cout << " BLUE";
            cout << " rows!" << endl << "What row colour would you like to score in?" << endl;
            cin >> rowColourChosen;

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
        cout << "Choose what index you want to place the sum of the rolls!" << endl;
        cin >> indexToScoreIn;
        hasBeenScored = qss.score(rollOfDice, rowColourTypeChosen, indexToScoreIn);
        if(!hasBeenScored && (redCanBeScored + yellowCanBeScored + blueCanBeScored) > 1){
            cout << "Would you like to leave row? Type Yes or No:" << endl;
            cin >> leaveRow;
            if (leaveRow == "yes")
                rowColourChosenIsCorrect = false;
                
        }
    }
    isActive = false; //player becomes inActive as he rolled
}
    
