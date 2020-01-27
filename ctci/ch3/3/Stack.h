typedef struct Stack Stack;

Stack* newStack();
int pushStack(Stack *s, void* elm);
int popStack(Stack *s, void** outVal);
int countStack(Stack *s);
