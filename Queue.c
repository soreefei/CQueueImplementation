#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

// Function Implementations

/* createQueue */
Queue *createQueue()
{
    Queue *queue = malloc(sizeof(Queue));
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
void insertName(Queue *queue, const char *newName)
{
    // Check queue existence
    if (!queue)
    {
        fprintf(stderr, "\nQueue does not exist.\n\n");
        return;
    }
    // Check for empty queue; will have to insert front node
    if (queue->size == 0)
    {
        insertFront(queue, newName);
        return;
    }
    // Create a new node
    Node *newNode = malloc(sizeof(Node));
    // Memory allocation failure
    if (!newNode)
    {
        fprintf(stderr, "\nMemory allocation failed for new node.\n\n");
        return;
    }
    // Allocate memory for name
    newNode->name = malloc(strlen(newName) + 1);
    // Memory allocation failure for name
    if (!newNode->name)
    {
        fprintf(stderr, "\nMemory allocation failed for name.\n\n");
        free(newNode);
        return;
    }
    // Copy string value into newNode
    strcpy(newNode->name, newName);
    // Set next pointer
    newNode->next = NULL;

    // Increment the size of the queue
    queue->size++;
    // Set the queue's new rear
    queue->rear->next = newNode;
    queue->rear = newNode;
    // Print the inserted name
    printf("\nInserted name: %s\n\n", newNode->name);
}

void insertFront(Queue *queue, const char *frontName)
{
    // Allocate for front node
    Node *frontNode = malloc(sizeof(Node));
    // Memory allocation failure
    if (!frontNode)
    {
        fprintf(stderr, "\nMemory allocation failed for new node.\n\n");
        return;
    }
    // Allocate memory for name
    frontNode->name = malloc(strlen(frontName) + 1);
    if (!frontNode->name)
    {
        fprintf(stderr, "\nMemory allocation failed for name.\n\n");
        free(frontNode);
        return;
    }
    strcpy(frontNode->name, frontName);
    frontNode->next = queue->front;
    queue->front = frontNode;

    if (queue->rear == NULL)
    {
        queue->rear = frontNode;
    }
    // Increment size of queue
    queue->size++;
    // Print the inserted name
    printf("\nInserted name at front: %s\n\n", frontNode->name);
    return;
}

/* deleteName */
void deleteName(Queue *queue, const char *deletedName)
{
    // Check queue existence
    if (!queue || !queue->front)
    {
        fprintf(stderr, "\nQueue does not exist or is empty.\n\n");
        return;
    }
    // Case if name deleted is front
    if (!strcmp(deletedName, queue->front->name))
    {
        // Set temporary pointer for later memory deallocation
        Node *temp = queue->front;
        // Move front to next name in queue
        queue->front = queue->front->next;
        // Memory deallocation
        free(temp->name);
        free(temp);
        // Decrement size of queue
        queue->size--;
        // Print deleted name
        printf("\nDeleted name: %s\n\n", deletedName);
        return;
    }
    // If name deleted not front
    else
    {
        // Pointer to traverse queue
        Node *nodePTR = queue->front;
        Node *prevNode = NULL;
        // Traverse queue
        while (nodePTR != NULL && strcmp(nodePTR->name, deletedName) != 0)
        {
            prevNode = nodePTR;
            nodePTR = nodePTR->next;
        }
        // If name not found
        if (nodePTR == NULL)
        {
            printf("Name '%s' not found in the queue.\n", deletedName);
            return;
        }
        // If name not at tail
        if (nodePTR)
        {
            prevNode->next = nodePTR->next;
            free(nodePTR->name);
            free(nodePTR);
        }
        // Decrement size of queue
        queue->size--;
        // Print deleted name
        printf("\nDeleted name: %s\n\n", deletedName);
        return;
    }
}

/* queueSize */
void queueSize(Queue *queue)
{
    // Check queue existence
    if (!queue)
    {
        fprintf(stderr, "\nQueue does not exist.\n\n");
        return;
    }
    // Print size of queue
    printf("\nSize of queue: %d\n\n", queue->size);
}

/* printQueue */
void printQueue(Queue *queue)
{
    // Check queue existence
    if (!queue || queue->size == 0)
    {
        printf("\nQueue is empty.\n\n");
        return;
    }
    // Print names in queue
    printf("\nHere are the names in the queue: [ ");
    Node *nodePTR = queue->front;
    while (nodePTR != NULL)
    {
        printf("%s", nodePTR->name);
        if (nodePTR->next != NULL)
        {
            printf(", ");
        }
        nodePTR = nodePTR->next;
    }
    printf(" ]\n\n");
}

void reverseQueue(Queue *queue)
{
    // Check if queue is empty
    if (!queue || queue->size == 0)
    {
        printf("\nQueue is empty, nothing to reverse.\n\n");
        return;
    }
    // Reverse the queue
    Node *nodePTR = queue->front;
    Node *prevNode = NULL;
    // Point rear to queue front
    queue->rear = nodePTR;
    while (nodePTR)
    {
        Node *nextNode = nodePTR->next;
        nodePTR->next = prevNode;
        prevNode = nodePTR;
        nodePTR = nextNode;
    }
    queue->front = prevNode;
    printf("\nReversed queue: ");
    printQueue(queue);
}