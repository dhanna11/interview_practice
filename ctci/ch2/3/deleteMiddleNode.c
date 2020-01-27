#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void deleteMiddleNode(Node* node) {
  assert(node);
  assert(node->next);
  Node* temp;
  if (!node || !node->next)
    return;
  
  node->data = node->next->data;
  temp = node->next;
  node->next = node->next->next;
  free(temp);
}

int main() {
  Node* node = malloc(sizeof(Node));
  node->data = 0;
  node->next = malloc(sizeof(Node));
  node->next->data = 1;
  node->next->next = malloc(sizeof(Node));
  Node* temp = node->next->next;
  node->next->next->data = 2;
  node->next->next->next = malloc(sizeof(Node));
  node->next->next->next->data = 3;
  node->next->next->next->next = NULL;
  
  for (Node* ptr = node; ptr != NULL; ptr = ptr->next) {
    printf("%d \n", ptr->data);
  }
  deleteMiddleNode(temp);
  for (Node* ptr = node; ptr != NULL; ptr = ptr->next) {
    printf("%d \n", ptr->data);
  }
  
}
