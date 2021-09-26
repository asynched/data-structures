#include <stdio.h>
#include "queue.h"

int main(void)
{
  queue_t *queue = create_queue();

  for (int i = 0; i < QUEUE_SIZE - 5; i++)
  {
    enqueue(queue, i);
  }

  print_queue(queue);

  for (int i = 0, length = queue->entries; i < length; i++)
  {
    dequeue(queue);
  }

  print_queue(queue);

  return 0;
}