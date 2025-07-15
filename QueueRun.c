#include <stdbool.h>
#include "Queue.h"
#include "Queue.c"

int main()
{
    // Create queue
    NameQueue *queue = createQueue();
    // Insert name into queue;
    char name[100];
    bool contiue = true;
    while (contiue)
    {
        printf("Please enter a name to insert into the queue: ");
        scanf("%s", name);
        insertName(queue, name);
        printf("Do you want to insert another name? ('y/n'): ");
        if (getchar() == 'N' || getchar() == 'n')
        {
            contiue = false;
        }
    }
    // Print queue
    printQueue(queue);
    return 0;
}