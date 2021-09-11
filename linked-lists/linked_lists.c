#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} NodeType;

typedef struct LinkedList
{
  int length;
  NodeType *elements;
} LinkedListType;

LinkedListType *createList()
{
  LinkedListType *list = (LinkedListType *)malloc(sizeof(LinkedListType));

  list->length = 0;
  list->elements = NULL;

  return list;
}

NodeType *createNode(int value)
{
  NodeType *node = (NodeType *)malloc(sizeof(NodeType));

  node->value = value;
  node->next = NULL;

  return node;
}

void appendNode(LinkedListType *list, int value)
{
  NodeType *newNode = createNode(value);

  if (list->elements == NULL)
  {
    list->elements = newNode;
    list->length = 1;
    return;
  }

  NodeType *lastElement = NULL;
  NodeType *temporary = list->elements;

  while (temporary != NULL)
  {
    lastElement = temporary;
    temporary = temporary->next;
  }

  lastElement->next = newNode;
  list->length++;
}

void popNode(LinkedListType *list)
{
  NodeType *temporary = list->elements;
  NodeType *aux = NULL;

  if (list->length == 0)
    return;

  if (list->length == 1)
  {
    aux = list->elements;
    list->elements = NULL;
    list->length--;
    free(aux);

    return;
  }

  for (int i = 0; i < list->length; ++i)
  {
    if (i == list->length - 2)
    {
      aux = temporary->next;
      temporary->next = NULL;
      list->length--;
      free(aux);
      return;
    }
    temporary = temporary->next;
  }
}

void printList(LinkedListType *list)
{
  NodeType *temporary = list->elements;

  printf("[ ");

  while (temporary != NULL)
  {
    printf("%d ", temporary->value);
    temporary = temporary->next;
  }

  printf("]\n");
}

void clearList(LinkedListType *list)
{
  const int LENGTH = list->length;

  for (int i = 0; i < LENGTH; ++i)
  {
    popNode(list);
  }
}
