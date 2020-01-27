#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int digit;
  struct Node* next;
} Node;

Node* sum_lists(Node* L0, Node* L1, int carryIn) {
  int sum = carryIn;
  if (!L0 && !L1 && !carryIn)
    return NULL;

  if (L0)
    sum += L0->digit;
  if (L1)
    sum += L1->digit;

  Node* new_node = malloc(sizeof(Node));
  new_node->digit = sum % 10;
  int carryOut = sum / 10;
  new_node->next = sum_lists((
			      L0) ? L0->next: NULL, (L1) ? L1->next : NULL, carryOut);
  return new_node;
}

int make_sum_list(Node* L0, Node* L1, Node** newHead) {
  if (!L0 && !L1)
    return 0;

  int carryOut = make_sum_list(L0->next, L1->next, newHead);
  int sum = L0->digit + L1->digit + carryOut;
  Node* newnewhead = malloc(sizeof(Node));
  newnewhead->next = *newHead;
  newnewhead->digit = sum % 10;
  *newHead = newnewhead;
  if (sum > 10)
    return 1;
  else
    return 0;
}

int getLength(Node* head) {
  int count = 0;
  for (Node* temp = head; temp != NULL; temp = temp->next)
    count++;
  
  return count;
}

Node* padList(Node* head, int n) {
  while (n > 0) {
    Node* temp = malloc(sizeof(Node));
    temp->digit =  0;
    temp->next = head;
    head = temp;
    n--;
  }
  return head;
}

Node* sum_lists_forward(Node* L0, Node* L1) {
  int n0 = getLength(L0);
  int n1 = getLength(L1);
  if (n0 > n1) 
    L1 = padList(L1, n0-n1);
  else if (n1 > n0)
    L0 = padList(L0, n1-n0);

  Node* newHead = NULL;
  int carryOut = make_sum_list(L0, L1, &newHead);
  if (carryOut) {
    Node* finalCarry = malloc(sizeof(Node));
    finalCarry->digit = 1;
    finalCarry->next = newHead;
    return finalCarry;
  } 
  return newHead;
}

void printll(Node* l) {
  for (Node* temp = l; temp != NULL; temp = temp->next)
    printf("%d", temp->digit);
}

int main() {
  Node* l0 = malloc(sizeof(Node));
  l0->digit = 7;
  l0->next = malloc(sizeof(Node));
  l0->next->digit = 1;
  l0->next->next = malloc(sizeof(Node));
  l0->next->next->digit = 6;
  l0->next->next->next = NULL;

  Node* l1 = malloc(sizeof(Node));
  l1->digit = 5;
  l1->next = malloc(sizeof(Node));
  l1->next->digit = 9;
  l1->next->next = malloc(sizeof(Node));
  l1->next->next->digit = 2;
  l1->next->next->next = malloc(sizeof(Node));
  l1->next->next->next->digit = 6;
  l1->next->next->next->next = malloc(sizeof(Node));
  l1->next->next->next->next->digit = 4;
  l1->next->next->next->next->next = NULL;

  Node* result = sum_lists(l0, l1, 0);
  printll(result);
  printf("\n");
  result = sum_lists_forward(l0, l1);
  printll(result);

}
