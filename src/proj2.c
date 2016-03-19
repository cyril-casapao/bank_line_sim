/**
* proj2.c
*
* This program simulates the work day at a bank and collects several statistics
* about the bank's efficiency. These statistics are as follows:
*
*   1) Total number of customers served in one day
*   2) Average time customers wait in line
*   3) Max time a customer waits in line
*   4) Average length of waiting line
*   5) Max length of waiting line
*
* @author Cyril Casapao
*/

#include "../inc/stats.h"
#include "../inc/queue.h"

// Change FILE_NAME to  use a different data file
#define FILE_NAME "../proj2.dat"

// The length of the work day to simulate (in minutes)
#define DAY_LENGTH 480

/* Function prototypes */
void simulation(int num_tellers);
int customer_arrival(int stats[]);

/**
* The main function. It simply asks the user to specify the number of tellers
* to use in the simulation and then runs it.
*
* @TODO: Input error checking.
*/
int main() {
    printf("Welcome to Bank Simulator!\n\n");
    printf("Please enter the number of tellers: ");
    int num_tellers;
    scanf("%d", &num_tellers);

    printf("Running simulation with %d tellers...\n\n", num_tellers);
    simulation(num_tellers);
    return 0;
}


/**
* Runs the simulation.
*
* @TODO: Figure out how to represent tellers.
*
* @param numTellers
*   The number of tellers
*/
void simulation(int num_tellers) {

    /* Read the data file */
    int stats[5];
    read_file(FILE_NAME, stats);

    /* Initialize statistics */
    int total_customers = 0; // This doubles as customer ID
    int sim_time;
    double service_time;

    /* Run the simulation for the work day */
    for(sim_time = 0; sim_time < DAY_LENGTH; sim_time++) {

        /* First, a random number of customers arrives */
        int num_arrivals = customer_arrival(stats);
        printf("%d customers have arrived!\n", num_arrivals);
        int current_customer = 0;

        /* Enqueue each new arrival */
        while(current_customer < num_arrivals) {
            enque(total_customers++);
            current_customer++;
        }

        /* Deque customers */
        while(!is_empty()) {
            int removed = deque();
            // printf("Customer %d is done!\n", removed);
        }

        /* Get the amount of time taken to service a customer
        service_time = expdist(AVG_SERVICE);
        printf("sim_time = %d, service_time = %0.5f\n", sim_time, service_time); */
    }


}


/**
* Determines how many customers arrive at any given minute.
*
* @param stats
*   The array containing the customer arrival probabilities
*/
int customer_arrival(int stats[]) {
    double random = rand() % 100;
    int prev_range = 0;
    int i;

    for(i = 0; i < 5; i++) {
        if(random < stats[i] + prev_range)
            break;
        prev_range += stats[i];
    }
    return i;
}
