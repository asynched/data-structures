#include <stdio.h>
#include "stack.h"

int main(void)
{
  StackType stack = createStack();

  for (int i = 1; i <= 5; ++i)
  {
    pushToStack(&stack, i * 5);
  }

  int poppedValue;

  while ((poppedValue = popFromStack(&stack)) != STACK_EMPTY_VALUE)
  {
    printf("[INFO]: Popped value = %d\n", poppedValue);
  }

  return 0;
}