/**
* stats.c
*
* This file contains functions used to collect required data.
*
* @author Cyril Casapao
*/
#include "../inc/stats.h"


/**
* Generates random values that are exponentially distributed with the
* given mean. This function is used to represent service times.
*
* @param mean
*   The value used to exponentially distribute numbers
*/
double expdist(double mean) {
    double r = rand();
    r /= RAND_MAX;
    return -mean * log(r);
}


/**
* Reads the file containing the customers/min stats and stores the information
* in a matrix. The index of the matrix represents the number of customers/min
* and the value is the percent of one minute intervals.
*
* For example, if stats[3] == 10, that means 10% of the time, there are 3
* customers/min.
*
* @param file_name
*   The name of the file containing the stats
*/
void read_file(char* file_name, int stats[]) {
    printf("Attempting to open %s...\n", file_name);

    FILE* f = fopen(file_name, "r");
    if(f == NULL) {
        exit(EXIT_FAILURE);
    }

    int offset;
    while(fscanf(f, "%d", &offset) != EOF) {
        fscanf(f, "%d", stats + offset);
    }
    fclose(f);

    printf("\nSuccessfully read %s.\n", file_name);
}
