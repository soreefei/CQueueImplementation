// Queue and node structures
/* Name in Queue */
typedef struct stringNode
{
    char *name;
    struct stringNode *next;
} NameNode;

/* Queue Structure */
typedef struct
{
    // Head (front) of the queue
    NameNode *front;
    // Tail (rear) of the queue
    NameNode *rear;
    // Size of the queue
    int size;
} NamesList;

// Queue Creation
NamesList *createQueue();

// Insert a name into queue
void insertName(NamesList *queue, const char *name);