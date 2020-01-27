#include <iostream>
#include <vector>

typedef struct Node {
  int data;
  Node* left;
  Node* right;
} Node;

void print_tree(Node* root) {
  if (root) {
    print_tree(root->left);
    print_tree(root->right);
    std::cout << root->data;
  }
  
}

Node* minimal_tree(std::vector<int> array, int low, int high) {
  if (low < high) {
    int median = (low + high) / 2;
    Node* node = new Node;
    node->data = array[median];
    node->left = minimal_tree(array, low, median - 1);
    node->right = minimal_tree(array, median + 1, high);
    return node;
  } else if (low == high) {
    Node* node = new Node;
    node->data = array[low];
    return node;
  }
    return NULL;
}

int main() {
  std::vector<int> a0({0,1,2,3,4,5,6});
  Node* root = minimal_tree(a0, 0, 6);
  print_tree(root);

}
