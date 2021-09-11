#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
  QueueType *queue = createQueue();

  for (int i = 1; i <= 5; i++)
    enqueue(queue, i * 5);

  printf("[QUEUE]: ");
  printQueue(queue);

  int queueItemValue = dequeue(queue);

  while (queueItemValue != EMPTY_QUEUE_VALUE)
  {
    printf("[ITEM]: %d\n", queueItemValue);
    queueItemValue = dequeue(queue);
  }

  return 0;
}
