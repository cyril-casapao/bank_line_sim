/**
* queue.h
*
* @author Cyril Casapao
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Node definition */
typedef struct node node;
struct node {
    int id;
    int arrival_time;
    node* next;
};

node* front;
node* rear;

/* Function prototypes */
void enque(int data);
int deque();
int is_empty();
int size();

#endif // _QUEUE_H_
