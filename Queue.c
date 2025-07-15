#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

// Function Implementations

/* createQueue */
NameQueue *createQueue()
{
    NameQueue *queue = malloc(sizeof(NameQueue));
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
void insertName(NameQueue *queue, const char *newName)
{
    // Check queue existence
    if (!queue)
    {
        fprintf(stderr, "Queue does not exist.\n");
        return;
    }
    // Check for empty queue; will have to insert front node
    if (queue->size == 0)
    {
        insertFront(queue, newName);
        return;
    }
    // Create a new node
    nameNode *newNode = malloc(sizeof(nameNode));
    // Memory allocation failure
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed for new node.\n");
        return;
    }
    // Allocate memory for name
    newNode->name = malloc(strlen(newName) + 1);
    // Memory allocation failure for name
    if (!newNode->name)
    {
        fprintf(stderr, "Memory allocation failed for name.\n");
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
    queue->rear = newNode;
    queue->rear->next = newNode;
    // Print the inserted name
    printf("Inserted name: %s\n", newNode->name);
}

void insertFront(NameQueue *queue, const char *frontName)
{
    // Allocate for front node
    nameNode *frontNode = malloc(sizeof(nameNode));
    // Memory allocation failure
    if (!frontNode)
    {
        fprintf(stderr, "Memory allocation failed for new node.\n");
        return;
    }
    // Allocate memory for name
    frontNode->name = malloc(strlen(frontName) + 1);
    if (!frontNode->name)
    {
        fprintf(stderr, "Memory allocation failed for name.\n");
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
    return;
}

/* deleteName */
void deleteName(NameQueue *queue, const char *deletedName)
{
    // Check queue existence
    if (!queue || !queue->front)
    {
        fprintf(stderr, "Queue does not exist or is empty.\n");
        return;
    }
    // Case if name deleted is front
    if (deletedName == queue->front->name)
    {
        // Set temporary pointer for later memory deallocation
        nameNode *temp = queue->front;
        // Move front to next name in queue
        queue->front = queue->front->next;
        // Memory deallocation
        free(temp->name);
        free(temp);
    }
    // If name deleted not front
    else
    {
        // Pointer to traverse queue
        nameNode *nodePTR = queue->front->next;
        // Traverse queue
        while (nodePTR != NULL)
        {
            if (nodePTR->name == deletedName)
            {
                // Deallocate memory for deletion
                free(nodePTR->name);
                free(nodePTR);
            }
            nodePTR = nodePTR->next;
        }
    }
    // Decrement size of queue
    queue->size--;
    // Print deleted name
    printf("Deleted name: %s\n", deletedName);
}

/* queueSize */
int queueSize(NameQueue *queue)
{
    // Statement
    printf("Size of queue: ");
    // Return size of queue
    return (queue) ? queue->size : 0;
}