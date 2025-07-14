#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

// Function Implementations

/* createQueue */
NamesList *createQueue()
{
    NamesList *queue = malloc(sizeof(NamesList));
    // Memory allocation failure
    if (!queue)
    {
        return NULL;
    }
    // Initialize the queue
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

/* insertName */
// Inserts a name into the queue
void insertName(NamesList *queue, const char *name)
{
    // Check if the queue is empty
    if (!queue)
    {
        return;
    }
}

/* deleteName */
