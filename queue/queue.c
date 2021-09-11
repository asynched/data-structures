#include <stdio.h>
#include <stdlib.h>

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

QueueType *createQueue()
{
  QueueType *queue = (QueueType *)malloc(sizeof(QueueType));

  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

void enqueue(QueueType *queue, int value)
{
  NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));

  newNode->value = value;
  newNode->next = NULL;

  if (queue->tail != NULL)
    queue->tail->next = newNode;

  queue->tail = newNode;

  if (queue->head == NULL)
  {
    queue->head = newNode;
  }
}

int dequeue(QueueType *queue)
{
  if (queue->head == NULL)
    return EMPTY_QUEUE_VALUE;

  NodeType *temporary = queue->head;
  int dequeueValue = temporary->value;

  queue->head = queue->head->next;

  if (queue->head == NULL)
    queue->tail = NULL;

  free(temporary);

  return dequeueValue;
}

void printQueue(QueueType *queue)
{
  NodeType *temporary = queue->head;

  while (temporary != NULL)
  {
    printf("%d -> ", temporary->value);
    temporary = temporary->next;
  }

  printf("END\n");
}