#include "banker.hpp"

void calculateNeed(int need[][R], int max[][R], int alloct[][R]) {
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            need[i][j] = max[i][j] - alloct[i][j]; // need = max - allocation
        }
    }
}

bool safeSequence(int avail[], int max[][R], int alloct[][R]) {
    int need[P][R];

    // find the current need all processes in the system
    calculateNeed(need, max, alloct); 

    // boolean array whose elements store true to represent finished processes, and false if process is not finished
    bool finishedProc[P] = {}; 
    // stores the safe sequence
    int safeSeq[P];
    
    // copying contents of available matrix to a buffer, whose contents will be modified later in the program
    int tempAvail[R];
    for (int i = 0; i < R; ++i) {
        tempAvail[i] = avail[i];
    }

    int counter = 0;
    // must loop while all processes in the system are not yet finsished
    while (counter < P) {
        
        bool found = false;
        for (int i = 0; i < P; ++i) {
            
            if (finishedProc[i] == 0) { // check if process is not finished

                int j;
                // loop through resources allocated to current process
                for (j = 0; j < R; ++j) { 
                    
                    // check if currrent process' resource needs can be accomodated
                    if (need[i][j] > tempAvail[j]) {
                        // break out of the loop if there exists a resource type whose request cannot be granted for the current process 
                        break;
                    }
                }

                // if all of the current processes resource needs have been met
                if (j == R) {

                    for (int h = 0; h < R; ++h) {
                        /*adding the resources allocated to the current process to the 
                        current available resources, which is in a sense freeing the resources
                        from the process, since all of its needs were met safely*/
                        tempAvail[h] += alloct[i][h];
                    }

                    // add the current process to the safeSeq array
                    safeSeq[counter++] = i;
                    // mark current process as finished
                    finishedProc[i] = 1; 
                    found = true;
                }
            }
        }
        if (found == false) {
            std::cout << "This system is not in a safe state. " << std::endl;

            return false;
        }
    
    }
    std::cout << "This system is in a safe state. " << std::endl;
    std::cout << "The safe sequence is: ";
    
    // printing safe sequence
    for (int i = 0; i < P; ++i) {
        std::cout << safeSeq[i] << " ";
    }
    std::cout << std::endl;
    return true;
}