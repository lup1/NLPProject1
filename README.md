# NLPProject1
### Casey Lishko, Chris Mckeever, Geethika Manojkumar, Poean Lu

"alphabet.txt" gives the vocabulary of the finite state machine. Next, "startState.txt" gives the starting state of the finite state machine, and "states.txt" gives all of the states that the finite state machine could go through. Finally, "finalState.txt" gives the accepting state of the finite state machine. "transitionTable.txt" gives the inputs that would cause the finite state machine to change states.

To run the program, you would compile the program using "g++ project1.cpp" and then run it by typing "./a.exe" into the command line. When prompted, type in the string that you wish to test. The string that would be accepted by the finite state machine using the current vocabulary is "bruh?". By default, the documents used to create the vocabulary and states gone through by the finite state machine are programmed into the code itself. To run the program using different vocabularies and/or states, one would need to replace the documents used. 

The file "project1.cpp" is the file corresponding to d1 of the assignment. It accepts the input "bruh?" with as many question marks following it as you want. The file "d2.cpp" and "d3.cpp" correspond to the programs required for steps d2 and d3 respectively. They will accept the input "bruh?" with any characters before or after it. Step d4 is fulfilled by both d2 and d3 once you change the files taken in by the test machine in the code to the alternative files with "baa" in their names.
