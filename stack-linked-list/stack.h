#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY_VALUE (-2147483648)

typedef struct Node
{
  int value;
  struct Node *next;
} NodeType;

typedef NodeType *StackType;

StackType createStack();
int pushToStack(StackType *stack, int value);
int popFromStack(StackType *stack);
