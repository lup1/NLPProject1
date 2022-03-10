#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <cstring>
#include <cstdio>
/*
#include "alphabet.txt"
#include "states.txt"
#include "finalStates.txt"
#include "transitionTable.txt"
#include "startState.txt"

#include "alphabet.txt"
*/

using namespace std;

/* D-Recognize Pseudocode

    function D-Recognize (tape, machine) returns accept or reject

    index = Beginning of tape
    currentState = firstState

    loop 
        if end of input has been reached then
            if currentState is an accept state then
                return accept
            else
                return reject
        else if transition-table[currentState, tape[index]] is empty then
            return reject
        else
            currentState = transitionTable[current-state, tape[index]]
            index++
            
    end

    */



int main(int argc, char* argv[]) {
// input files as command line arguments?
    int i = 0;  // iterator to help with putting states into array
    string input;
    cout << "Please enter a string:" << endl;
    cin >> input;
    
    
    /* Reading txt files */
    
    ifstream stateFd;
    ifstream alphaFd;
    ifstream startFd;
    ifstream transitionFd;
    ifstream finalFd;

    string currState;
    vector<string> allStates;
    stateFd.open("states.txt");

    while (!stateFd.eof()) {
        stateFd >> currState;
        allStates.push_back(currState);
    }
    stateFd.close();

    string startState;
    startFd.open("startState.txt");
    if (startFd) {
        startFd >> startState;
    }
    
    vector<string> alphabet;
    alphaFd.open("alphabet.txt");
    while (!alphaFd.eof()) {
        alphaFd >> currState;
        alphabet.push_back(currState);
    }
    
    // declare a 2d vector that serves as the transition table
    vector<vector<string>> transitionMatrix;

    // resize it so that it has as many rows as there are states
    transitionMatrix.resize(allStates.size());

    // resize each row so that it has as many columns as there are items in the input alphabet
    for (int i = 0; i < transitionMatrix.size(); ++i) {
        transitionMatrix[i].resize(alphabet.size());
        transitionMatrix[i][0] = allStates.at(i);
        transitionMatrix[0][i] = alphabet.at(i);
    }

    transitionFd.open("transitionTable.txt");
    int i = 1;
    int j = 1;

    // will store the first comma-separated string on each line as we read it
    currState = startState;
    // will store the first comma-separated string on the line from which we're moving on
    string prevState = currState;
    while (!transitionFd.eof()) {
        getline(transitionFd,currState,',');
        if (prevState == currState) {
            // do nothing
        } else {
            // if the state read on the current line differs from that of the previous
            // increment the row counter
            i++;
        }

        // read the remaining comma-separated strings and store them as transitions for the state
        while (j < alphabet.size()) {
            getline(transitionFd,transitionMatrix[i][j],',');
            j++;
        }

        // store what we just read 
        prevState = transitionMatrix[i][0];
        j = 1;
    }
    /*
        while(j < alphabet.size()) {
            getline(transitionFd,transitionMatrix[i][j],',');
            j++;
        }
        i++;
        j = 0;
    }*/

    // print out the matrix
    for (int i = 0; i < transitionMatrix.size(); ++i) {
        for (int j = 0; j < transitionMatrix[i].size(); ++j) {
            cout << transitionMatrix[i][j] + " ";
        }
        cout << endl;
    }
    
    vector<string> finalStates;
    finalFd.open("finalStates.txt");
    while (!finalFd.eof()) {
        finalFd >> currState;
        finalStates.push_back(currState);
    }
    
    //d recognize function

    // int index = input[0];
    // currState = startState;
    

    // for(int i = 0; i < input.length(); i++)
    // {
    //     //if input matches the alphabet then the currState is an accepted state
    //     //if((string)input[i] == transitionMatrix[i][1])/*alphabet*/
    //     if(strcmp(input[i], transitionMatrix[i][1]))
    //     {
    //         currState = "accept";
    //     }
    //     if(i = input.length() - 1)
    //     {
    //         // assuming finalStates.txt can have multiple accepting states

    //         /*
    //         for (x : finalStates) {
    //             if (x == currState) {
    //                 cout << "Accept" << endl;
    //             }
    //         }
    //         */

    //         if(currState == finalStates.at(0)) {
    //             cout << "Accept" << endl;
    //             break;
    //         }
    //         else {
    //             cout << "Reject" << endl;
    //             break;
    //         }
    //     }
    //     else if(transitionMatrix[currState, input[i]].size() == 0)
    //     {
    //         cout << "Reject" << endl;
    //     }
    // }
    
    



    stateFd.close();
    alphaFd.close();
    startFd.close();
    transitionFd.close();
    finalFd.close();
    
    // /*
    // for (int i = 0; i < input.length(); ++i) {
    //     if (string[i])
    // }
    // */

    // string states[0 /*input length when we figure out states*/];
    // string transitionTable[sizeof(alphabet) * sizeof(states)];

    // newFile.open("alphabet.txt",ios::in);
    // if (newFile.is_open()){
    // while(getline(newFile, alphabet[i]))
    //     i++;
    // }
    // newFile.close();


    
    return 0;
}
