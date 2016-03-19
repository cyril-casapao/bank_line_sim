/**
* queue.h
*
* @author Cyril Casapao
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

/* Includes */
#include <stdio.h>

/* Node definition */
typedef struct node node;
struct node {
    int id;
    int arrival_time;
    node* next;
};

/* Function prototypes */
void enque(int data);
node deque();
int size();

#endif // _QUEUE_H_
