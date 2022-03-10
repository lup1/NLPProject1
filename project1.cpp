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
    
    vector<vector<string>> transitionMatrix;
    transitionFd.open("transitionTable.txt");
    int i, j = 0;
    while (!transitionFd.eof()) {
        while(j < alphabet.size()) {
            getline(transitionFd,transitionMatrix[i][j],',');
            j++;
        }
        i++;
        j = 0;
    }
    
    vector<string> finalStates;
    finalFd.open("finalStates.txt");
    while (!finalFd.eof()) {
        finalFd >> currState;
        finalStates.push_back(currState);
    }
    
    //d recognize function

    int index = input[0];
    currState = startState;
    

    for(int i = 0; i < input.length(); i++)
    {
        //if input matches the alphabet then the currState is an accepted state
        //if((string)input[i] == transitionMatrix[i][1])/*alphabet*/
        if(strcmp(input[i], transitionMatrix[i][1]))
        {
            currState = "accept";
        }
        if(i = input.length() - 1)
        {
            // assuming finalStates.txt can have multiple accepting states

            /*
            for (x : finalStates) {
                if (x == currState) {
                    cout << "Accept" << endl;
                }
            }
            */

            if(currState == finalStates.at(0)) {
                cout << "Accept" << endl;
                break;
            }
            else {
                cout << "Reject" << endl;
                break;
            }
        }
        else if(transitionMatrix[currState, input[i]].size() == 0)
        {
            cout << "Reject" << endl;
        }
    }
    
    



    stateFd.close();
    alphaFd.close();
    startFd.close();
    transitionFd.close();
    finalFd.close();
    
    /*
    for (int i = 0; i < input.length(); ++i) {
        if (string[i])
    }
    */

    string states[0 /*input length when we figure out states*/];
    string transitionTable[sizeof(alphabet) * sizeof(states)];

    // newFile.open("alphabet.txt",ios::in);
    // if (newFile.is_open()){
    // while(getline(newFile, alphabet[i]))
    //     i++;
    // }
    // newFile.close();


    
    return 0;
}
