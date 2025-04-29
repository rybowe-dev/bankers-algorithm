// Rylan Bowe
// Banker's algorithm implementation, uses text file to simulate system state
// 4/28/20

#include "banker.hpp"

int main () {
    
    int processes[P] = {0, 1, 2, 3, 4}; // stores different processes in system
    int allocation[P][R]; // matrix for number of resources of each type allocated to each process
    int maximum[P][R]; // matrix for maximum number of resources of each type that each process will need
    int available[R]; // number of available resources for each type

    // opening data file that contains system information
    std::ifstream in;
    in.open("data.txt");

    if(!(in.is_open())) {
        std::cout << "failed to open data file " << std::endl;
        return 0;
    }

    // reading the allocation matrix and writing its contents to allocated[][]
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            in >> allocation[i][j];
        }
    }
    
    // reading the maximum matrix and writing its contents to maximum[][]
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            in >> maximum[i][j];
        }
    }

    // reading available and writing its contents to available[]
    for (int i = 0; i < R; ++i) {
        in >> available[i];
    }

    // invoking safeSequence() to check if system is in a safe state, and if yes, printing the safe sequence
    safeSequence(available, maximum, allocation);

}