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
* This program automatically runs the simulation multiple times for varying
* numbers of tellers.
*
* @author Cyril Casapao
*/

#include "../inc/stats.h"
#include "../inc/queue.h"

// Change FILE_NAME to use a different data file
#define FILE_NAME "../proj2.dat"

// The length of the work day to simulate (in minutes)
#define DAY_LENGTH 480

// The minimum number of tellers
#define MIN_TELLER_COUNT 4

// The maximum number of tellers
#define MAX_TELLER_COUNT 7

/* Function prototypes */
void simulation(int num_tellers, int stats[]);
int customer_arrival(int stats[]);
int check_tellers(int tellers[], int num_tellers);
void decrement_tellers(int tellers[], int num_tellers);

/**
* The main function. It simply asks the user to specify the number of tellers
* to use in the simulation and then runs it.
*
* @TODO: Input error checking.
*/
int main() {
    printf("Welcome to Bank Simulator!\n\n");

    /* Read the data file */
    int stats[5];
    read_file(FILE_NAME, stats);

    /* Run the simulation multiple times for different amounts of tellers */
    int num_tellers;
    for(num_tellers = MIN_TELLER_COUNT; num_tellers <= MAX_TELLER_COUNT; num_tellers++) {
        printf("Running simulation with %d tellers...\n\n", num_tellers);
        simulation(num_tellers, stats);
    }
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
void simulation(int num_tellers, int stats[]) {

    // See free_tellers() documentation for details about this array
    int tellers[num_tellers];

     // This doubles as customer ID
    int total_customers = 0;

    /* Run the simulation for the work day */
    int sim_time;
    for(sim_time = 0; sim_time < DAY_LENGTH; sim_time++) {

        /* First, decrease time left in any unavailable tellers */
        decrement_tellers(tellers, num_tellers);

        /* Second, a random number of customers arrives */
        int num_arrivals = customer_arrival(stats);
        int current_customer = 0;

        /* Third, enque each new arrival */
        while(current_customer < num_arrivals) {
            enque(total_customers++);
            current_customer++;
        }

        /* Lastly, move customers to available tellers if possible */
        int teller_num;
        while(teller_num = check_tellers(tellers, num_tellers), teller_num > 0 && !is_empty()) {
            deque();
            tellers[teller_num] = (int) expdist(AVG_SERVICE);
        }
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


/**
* Checks if there are any free tellers. Each index of the tellers[] array
* holds the number of minutes until that teller is free. For exammple, if
* tellers[2] == 3.0, that means there are 3 minutes until teller #2 is
* available.
*
* @param tellers
*   The array of tellers
* @param num_tellers
*   The number of tellers
* @return
*   The index of the free teller; -1 if there are no free tellers
*/
int check_tellers(int tellers[], int num_tellers) {
    int i;
    for(i = 0; i < num_tellers; i++) {
        if(tellers[i] == 0)
            return i;
    }
    return -1;
}


/**
* Decreases the time remaining for every unavailable teller by 1.
*
* @param tellers
*   The array of tellers
* @param num_tellers
*   The number of tellers
*/
void decrement_tellers(int tellers[], int num_tellers) {
    int i;
    for(i = 0; i < num_tellers; i++) {
        if(tellers[i] > 0)
            tellers[i]--;
    }
}
