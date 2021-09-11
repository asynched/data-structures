#include <stdio.h>
#include "linked_lists.h"

int main(void)
{
  LinkedListType *list = createList();

  appendNode(list, 10);
  appendNode(list, 15);
  appendNode(list, 20);

  printf("[INFO]: List's length: %d\n", list->length);
  printList(list);

  popNode(list);

  printf("[INFO]: List's length: %d\n", list->length);
  printList(list);

  return 0;
}
