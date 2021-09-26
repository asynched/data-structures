#include <stdio.h>
#include "queue.h"

int main(void)
{
  queue_t *queue = create_queue();
  const int RANGE = 10;

  for (int i = 0; i < RANGE; i++)
    enqueue(queue, create_node(i));

  print_queue(queue);

  for (int i = 0; i < RANGE; i++)
    dequeue(queue, NULL);

  print_queue(queue);

  return 0;
}