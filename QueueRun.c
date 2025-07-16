#include <stdbool.h>
#include "Queue.h"
#include "Queue.c"

int main()
{
    // Create queue
    Queue *queue = createQueue();
    // Insert name into queue;
    char name[100];
    // Choice variable for options
    int choice;
    bool cycle = true;
    printf("\nWelcome to the Queue Implementation!\n");
    while (cycle)
    {
        printf("Options:\n1. Insert Name\n2. Delete Name\n3. Print Queue\n4. Queue Size\n5. Reverse Queue\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // enQueue Implementation
            bool Continue = true;
            printf("\nenQueue Implementation\n======================\n");
            while (Continue)
            {
                printf("Please enter a name to insert into the queue: ");
                scanf("%s", name);
                insertName(queue, name);
                printf("Do you want to insert another name? ('y/n'): ");
                if (getchar() == 'N' || getchar() == 'n')
                {
                    Continue = false;
                }
            }
            break;
        case 2:
            // deQueue Implementation
            Continue = true;
            printf("\ndeQueue Implementation\n======================\n");
            while (Continue)
            {
                printf("Please enter a name to delete from the queue: ");
                scanf("%s", name);
                deleteName(queue, name);
                printf("Do you want to delete another name? ('y/n'): ");
                if (getchar() == 'N' || getchar() == 'n')
                {
                    Continue = false;
                }
            }
            break;
        case 3:
            // Print queue
            printQueue(queue);
            break;
        case 4:
            queueSize(queue);
            break;
        case 5:
            printf("\nreverseQueue Implementation\n==========================\n");
            reverseQueue(queue);
            break;
        case 6:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}