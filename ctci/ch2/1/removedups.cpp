#include <unordered_set>
#include <iostream>

template<typename T> 
struct Node {
  T data;
  Node* next;
};

void removeNode(Node<int>* current, Node<int>* prev) {
  prev->next = current->next;
  delete current;
}

void removeDuplicates(Node<int>* head) {
  std::unordered_set<int> s;
  Node<int>* prev = NULL;
  Node<int>* current = head;
  while (current != NULL) {
    if (s.find(current->data) != s.end()) {
      removeNode(current, prev);
      current = prev->next;
    }
    else {
      s.insert(current->data);
      prev = current;
      current = current->next;
    }
  }
}

int main() {
  Node<int>* head = new Node<int>();
  head->data = 10;
  head->next = new Node<int>();
  head->next->data = -5;
  head->next->next = new Node<int>();
  head->next->next->data = -5;
  head->next->next->next = new Node<int>();
  head->next->next->next->data = 4;
  removeDuplicates(head);
  Node<int>* temp = head;
  while (temp != NULL) {
    std::cout << temp->data << "\n";
    temp = temp->next;
  }
}
