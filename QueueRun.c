#include <stdio.h>
#include "Queue.h"
#include "Queue.c"

int main()
{
    // Create queue
    NameQueue *queue = createQueue();
    // Insert name into queue;
    char name[100];
    printf("Please enter a name to insert into the queue: ");
    scanf("%s", name);
    insertName(queue, name);
    // Print names in queue
    printf("Here are the names in the queue: [ ");
    nameNode *nodePTR = queue->front;
    while (nodePTR != NULL)
    {
        printf("%s, ", nodePTR->name);
        nodePTR = nodePTR->next;
    }
    printf(" ]\n");
    return 0;
}