#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY_VALUE (-2147483648)

int myStack[STACK_LENGTH];
int top = EMPTY;

int push(int value)
{
  if (top >= STACK_LENGTH - 1)
    return 0;

  top++;
  myStack[top] = value;

  return 1;
}

int pop()
{
  if (top == EMPTY)
    return STACK_EMPTY_VALUE;

  return myStack[top--];
}