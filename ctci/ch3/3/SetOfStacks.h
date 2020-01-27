typedef struct SetOfStacks SetOfStacks;

SetOfStacks* newSetOfStacks(size_t maxSubStackSize);
int pushSetOfStacks(SetOfStacks *S, void* elm);
int popSetOfStacks(SetOfStacks *S, void** outVal);
