#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

int ktothelastnode(Node* head, int k, Node** knode) {
  int count;
  if (!head)
    return 0;
  if (!head->next)
    count = 0;
  else 
    count = 1 + ktothelastnode(head->next, k, knode);

  if (count == k)
    *knode = head;
  
  return count;
}

Node* ktothelastItr(Node* head, int k) {
  int count = 0;
  Node* slowptr = head;
  Node* runahead = head;
  while (runahead != NULL && count < k) {
    count+=1;
    runahead = runahead->next;
  }
  if (count != k)
    return NULL;

  while (slowptr != NULL && runahead != NULL) {
    if (runahead->next == NULL)
      return slowptr;
    else {
      slowptr=slowptr->next;
      runahead = runahead->next;
    }
  }
  return NULL;
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 0;
  head->next = malloc(sizeof(Node));
  head->next->data = 1;
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 2;
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 3;
  int k = 1;
  Node* knode;
  ktothelastnode(head, k, &knode);
  printf("%d\n", knode->data);
  knode = ktothelastItr(head, k);
  printf("%d\n", knode->data);
}
