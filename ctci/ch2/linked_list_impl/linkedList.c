#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node;

Node* newNode() {
  Node* temp = malloc(sizeof(Node));
  if (!temp)
    return NULL;
  temp->next = NULL;
  temp->value = 0;
}

void freeList(Node* head) {
  while (head != NULL) {
    Node* temp = head->next;
    free(head);
    head = temp;
  }
  return;
}

void prependLinkedList(Node** head, Node* newNode) {
  newNode->next = *head;
  *head = newNode;
}

Node* createLinkedList(int numNodes) {
  Node* head = NULL;
  for (int i = 0; i < numNodes; i++) {
    Node* temp = newNode();
    if (!temp) {
      freeList(head);
      return NULL;
    }    
    temp->value = i;
    /* Prepend Node instead of appending! */
    prependLinkedList(&head, temp);
  }
  return head;
}

void printList(Node* head) {
  while (head != NULL) {
    printf("%d\n", head->value);
    head = head->next;
  }
}

int main() {
  Node* list = createLinkedList(5);
  printList(list);
  freeList(list);
  return 0;
}
