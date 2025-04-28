// header file for bankers algorithm implementation

#ifndef MY_BANKER_HPP
#define MY_BANKER_HPP

#include <iostream>
#include <fstream>

const int P = 5; // number of process
const int R = 3; // number of resources

// function that is used to calculate the need of all the processes in the system
void calculateNeed(int need[][R], int max[][R], int alloct[][R]);
// function that checks if the system is in a safe state
bool safeSequence(int avail[], int max[][R], int alloct[][R]);

#endif