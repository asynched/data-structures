#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
  struct node *previous;
} node_t;

typedef void (*queue_callback_t)(node_t *);

typedef struct queue
{
  node_t *entry;
} queue_t;

/**
 * Creates a node and allocates it on the heap
 * 
 * @param value Node's integer value
 * @returns A new node pointer 
 */
node_t *create_node(int value)
{
  node_t *node = (node_t *)malloc(sizeof(node_t));

  node->value = value;
  node->next = NULL;
  node->previous = NULL;

  return node;
}

/**
 * @returns A double ended queue
 */
queue_t *create_queue()
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  queue->entry = NULL;
  return queue;
}

/**
 * Adds a node to the end of the queue
 * 
 * @param self Queue to append the node to
 * @param node Node to append to the end of the queue
 */
void enqueue(queue_t *queue, node_t *node)
{
  if (queue->entry == NULL)
  {
    queue->entry = node;
    return;
  }

  node_t *temporary = queue->entry;
  node_t *last_node = temporary;

  while (temporary != NULL)
  {
    last_node = temporary;
    temporary = temporary->next;
  }

  node->previous = last_node;
  last_node->next = node;
}

/**
 * Removes an item from the beginning of the queue
 * 
 * @param self Queue to remove the item from
 * @param callback Optional callback to run on the removed item
 */
void dequeue(queue_t *queue, queue_callback_t callback)
{
  if (queue->entry == NULL)
    return;

  node_t *temporary = queue->entry;
  queue->entry = temporary->next;

  if (callback != NULL)
    callback(temporary);

  free(temporary);
}

/**
 * Prints a node
 * 
 * @param node Node to be printed
 */
void print_node(node_t *node)
{
  printf("Node<value=%d, previous=%p, next=%p>\n", node->value, node->previous, node->next);
}

/**
 * Prints a queue
 * 
 * @param self Queue to be printed
 */
void print_queue(queue_t *queue)
{
  node_t *temporary = queue->entry;

  while (temporary != NULL)
  {
    printf("%d -> ", temporary->value);
    temporary = temporary->next;
  }

  printf("NULL\n");
}