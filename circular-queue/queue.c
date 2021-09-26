#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
#define QUEUE_EMPTY (-2147483648)

typedef struct queue
{
  int elements[QUEUE_SIZE];
  int head, tail, entries;
} queue_t;

/**
 * Creates a circular queue data structure
 * @returns A circular queue
 */
queue_t *create_queue()
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

  queue->head = 0;
  queue->tail = 0;
  queue->entries = 0;

  return queue;
}

/**
 * Helper function to indicate if the queue is empty or not
 * 
 * @param queue Queue to verify if it is empty
 * @returns An integer value indicating if the queue is empty or not
 */
int queue_empty(queue_t *queue)
{
  return queue->entries == 0;
}

/**
 * Helper function to indicate if the queue is full or not
 * 
 * @param queue Queue to verify if it is full
 * @returns An integer value indicating if the queue is full or not
 */
int queue_full(queue_t *queue)
{
  return queue->entries == QUEUE_SIZE;
}

/**
 * Deletes a queue from memory
 * 
 * @param queue Queue to be dealocated from memory
 */
void queue_destroy(queue_t *queue)
{
  free(queue);
}

/**
 * Appends an item to the end of the queue
 * 
 * @param queue Queue to add an element to
 * @param value Value to be added to the end of the list
 */
int enqueue(queue_t *queue, int value)
{
  if (queue_full(queue))
  {
    return -1;
  }

  queue->elements[queue->tail] = value;
  queue->entries++;
  queue->tail = (queue->tail + 1) % QUEUE_SIZE;

  return 0;
}

/**
 * Removes and returns an item from the beginning of the queue
 * 
 * @param queue Queue to get the item from
 * @returns The value popped from the head of the queue
 */
int dequeue(queue_t *queue)
{
  if (queue_empty(queue))
  {
    return QUEUE_EMPTY;
  }

  int result = queue->elements[queue->head];
  queue->head = (queue->head) % QUEUE_SIZE;
  queue->entries--;

  return result;
}

/**
 * Prints the queue to stdout
 * 
 * @param queue Queue to be printed
 */
void print_queue(queue_t *queue)
{
  for (int i = 0; i < queue->entries; i++)
  {
    printf("%d -> ", queue->elements[i]);
  }

  printf("NULL\n");
}