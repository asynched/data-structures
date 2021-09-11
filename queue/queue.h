#define EMPTY_QUEUE_VALUE (-2147483648)

typedef struct Node
{
  int value;
  struct Node *next;
} NodeType;

typedef struct Queue
{
  NodeType *head;
  NodeType *tail;
} QueueType;

typedef void (*QueueCallbackType)(int);

QueueType *createQueue();
void enqueue(QueueType *queue, int value);
int dequeue(QueueType *queue);
void printQueue(QueueType *queue);
