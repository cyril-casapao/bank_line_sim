/**
* stats.h
*
* @author Cyril Casapao
*/
#ifndef _STATS_H_
#define _STATS_H_

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>
#include <math.h>

/* Macro definitions */
#define AVG_SERVICE 2.0

/* Prototypes */
double expdist(double mean);
void read_file(char* file_name, int stats[]);

#endif // _STATS_H_
