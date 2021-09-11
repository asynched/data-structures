#include <stdio.h>
#include "stack.h"

int main(void)
{
  push(5);
  push(7);

  int poppedValue;

  while ((poppedValue = pop()) != STACK_EMPTY_VALUE)
  {
    printf("[INFO]: Value = %d\n", poppedValue);
  }

  return 0;
}