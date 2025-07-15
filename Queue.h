#ifndef QUEUE_H
#define QUEUE_H

// Queue and node structures
/* Name in Queue */
typedef struct nameNode
{
    char *name;
    struct nameNode *next;
} nameNode;

/* Queue Structure */
typedef struct NameQueue
{
    // Head (front) of the queue
    nameNode *front;
    // Tail (rear) of the queue
    nameNode *rear;
    // Size of the queue
    int size;
} NameQueue;

// Queue Creation
NameQueue *createQueue();

// Insert a name into queue
void insertName(NameQueue *queue, const char *newName);

void insertFront(NameQueue *queue, const char *frontName);

// Delete name from queue
void deleteName(NameQueue *queue, const char *deletedName);

// Returnrs size of queue
int queueSize(NameQueue *queue);

void printQueue(NameQueue *queue);

#endif