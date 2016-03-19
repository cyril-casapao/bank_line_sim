/**
* queue.c
*
* This source file contains an implementation of a queue based on a linked list.
*
* @author Cyril Casapao
*/
#include "../inc/queue.h"

/**
* Adds a node to the end of the queue with the given data.
*
* @param id
*   The ID of the customer to add to the end of the queue
*/
void enque(int id) {
    node* to_enque = (node*) malloc(sizeof(node));
    to_enque->id = id;
    to_enque->next = NULL;

    if(front == NULL && rear == NULL) {
        // Case 1: Insert into empty queue
        front = to_enque;
        rear = to_enque;
    } else {
        // Case 2: Insert into non-empty queue
        rear->next = to_enque;
        rear = to_enque;
    }
}


/**
* Removes the node at the front of the queue. Additionally, this function
* returns the ID of the node that is dequeued.
*
* @return
*   The ID of the removed node; -1 if the queue is empty
*/
int deque() {
    int id;
    node* to_deque = front;

    if(front == NULL) {
        // Case 1: Queue is empty
        id = -1;
    } else if(front == rear) {
        // Case 2: Queue has one element
        id = front->id;
        front = NULL;
        rear = NULL;
        free(to_deque);
    } else {
        // Case 3: Queue has more than one element
        id = to_deque->id;
        front = front->next;
        free(to_deque);
    }
    return id;
}


/**
* Returns whether or not the queue is empty.
*
* @return
*   1 if the queue is empty, 0 otherwise
*/
int is_empty() {
    return (front == NULL && rear == NULL) ? 1 : 0;
}


/**
* Returns the number of nodes in the queue.
*
* @return
*   The number of nodes in the queue.
*/
int size() {
    node* current = front;
    int count = 0;
    while(current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}
