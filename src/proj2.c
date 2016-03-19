/**
* proj2.c
*
* @author Cyril Casapao
*/

#include <stdio.h>
#include "../inc/stats.h"

// Change FILE_NAME to  use a different data file
#define FILE_NAME "../proj2.dat"

void simulation(int numTellers);

/**
* The main function. It simply asks the user to specify the number of tellers
* to use in the simulation and then runs it.
*
* @TODO: Input error checking.
*/
int main() {
    printf("Welcome to Bank Simulator!\n\n");
    printf("Please enter the number of tellers: ");
    int numTellers;
    scanf("%d", &numTellers);

    printf("Running simulation with %d tellers...\n\n", numTellers);
    simulation(numTellers);
    return 0;
}


/**
* Runs the simulation.
*
* @param numTellers
*   The number of tellers
*/
void simulation(int numTellers) {

    // Read the data file
    int stats[5];
    read_file(FILE_NAME, stats);
}
