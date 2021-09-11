#include <stdio.h>
#include "linked_lists.h"

int main(void)
{
  LinkedListType *list = createList();

  for (int i = 1; i <= 5; ++i)
    appendNode(list, i * 5);

  printf("[INFO]: List's length: %d\n", list->length);
  printList(list);

  popNode(list);
  printf("[INFO]: List's length: %d\n", list->length);
  printList(list);

  clearList(list);
  printf("[INFO]: Cleared list\n");
  printList(list);

  return 0;
}
