#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY_VALUE (-2147483648)

typedef struct Node
{
  int value;
  struct Node *next;
} NodeType;

typedef NodeType *StackType;

StackType createStack()
{
  StackType stack = (StackType)malloc(sizeof(StackType));
  return stack;
}

int pushToStack(StackType *stack, int value)
{
  NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));

  if (newNode == NULL)
    return 0;

  newNode->value = value;
  newNode->next = *stack;

  *stack = newNode;

  return 1;
}

int popFromStack(StackType *stack)
{
  // This doesn't feel right, lol. I'll fix it later
  if ((*stack)->next == NULL)
    return STACK_EMPTY_VALUE;

  int value = (*stack)->value;

  NodeType *temporary = *stack;
  *stack = (*stack)->next;

  free(temporary);

  return value;
}
