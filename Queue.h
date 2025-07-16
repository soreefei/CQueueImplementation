#ifndef QUEUE_H
#define QUEUE_H

// Queue and node structures
/* Name in Queue */
typedef struct Node
{
    char *name;
    struct Node *next;
} Node;

/* Queue Structure */
typedef struct Queue
{
    // Head (front) of the queue
    Node *front;
    // Tail (rear) of the queue
    Node *rear;
    // Size of the queue
    int size;
} Queue;

// Queue Creation
Queue *createQueue();

// Insert a name into queue
void insertName(Queue *queue, const char *newName);

void insertFront(Queue *queue, const char *frontName);

// Delete name from queue
void deleteName(Queue *queue, const char *deletedName);

// Returnrs size of queue
void queueSize(Queue *queue);

void printQueue(Queue *queue);

void reverseQueue(Queue *queue);

#endif