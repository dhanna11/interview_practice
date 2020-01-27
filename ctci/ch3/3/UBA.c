#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "UBA.h"

typedef struct Uba {
  void** array;
  size_t capacity;
  size_t currentSize;
} Uba;

Uba* newUba(size_t initialCapacity) {
  Uba *uba = malloc(sizeof(Uba));
  uba->capacity = initialCapacity;
  uba->array = malloc(sizeof(void*) * initialCapacity);
  uba->currentSize = 0;
  return uba;
}

int UbaEmplace(Uba* uba, void* elm) {
  if (uba->currentSize == uba->capacity) {
    void *biggerArray = realloc(uba->array, uba->capacity * 2);
    if (!biggerArray) {
      fprintf(stderr, "Failled to realloc bigger array!");
      free(elm);
      return -1;
    }
    uba->array = biggerArray;
    uba->capacity *= 2;
  }
  uba->array[uba->currentSize++] = elm;
  return 0;
}

int UbaRemove(Uba* uba, size_t index) {
  if (index > uba->currentSize)
    return -1;
  free(uba->array[index]);
  // if index is last element in array, decrement size
  if (index == (uba->currentSize -1))
    uba->currentSize--;
  /* 
     Shrink uba by 4! NOT 2. Refer to 15-122 Big O analysis!
   */
  if (uba->currentSize  < (uba->capacity / 4)) {
    void* smallerArray = realloc(uba->array, uba->capacity / 4);
    if (!smallerArray) {
      fprintf(stderr, "Failed to realloc smaller arrary!");
      return -1;
    }
    uba->array = smallerArray;
  }  
  return 0;
}

void* UbaBack(Uba* uba) {
  return uba->array[uba->currentSize-1];
}
