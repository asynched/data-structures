#define QUEUE_SIZE 10
#define QUEUE_EMPTY (-2147483648)

typedef struct queue
{
  int elements[QUEUE_SIZE];
  int head, tail, entries;
} queue_t;

queue_t *create_queue();
int queue_empty(queue_t *queue);
void queue_destroy(queue_t *queue);
int enqueue(queue_t *queue, int value);
int dequeue(queue_t *queue);
void print_queue(queue_t *queue);
