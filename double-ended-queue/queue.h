typedef struct node
{
  int value;
  struct node *next;
  struct node *previous;
} node_t;

typedef struct queue
{
  node_t *entry;
} queue_t;

typedef void (*queue_callback_t)(node_t *);

node_t *create_node(int value);
queue_t *create_queue();
void enqueue(queue_t *queue, node_t *node);
void dequeue(queue_t *queue, queue_callback_t callback);
void print_node(node_t *node);
void print_queue(queue_t *queue);
