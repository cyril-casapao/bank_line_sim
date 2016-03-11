/**
* proj2.c
*
* @author Cyril Casapao
*/

#include <stdio.h>

void simulation(int numTellers);

/**
* The main function. It simply asks the user to specify the number of tellers
* to use in the simulation and then runs it.
*
* @TODO: Input error checking.
*/
int main() {
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
    printf("yaaaay\n");
}
