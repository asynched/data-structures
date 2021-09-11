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

LinkedListType *createList();
void appendNode(LinkedListType *list, int value);
void printList(LinkedListType *list);
void popNode(LinkedListType *list);
