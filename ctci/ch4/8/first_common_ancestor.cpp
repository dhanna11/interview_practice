#include <iostream>

typedef struct Node {
  Node* left;
  Node* right;
  int d;
  Node(int d) : d(d) {}
} Node;

bool in_tree(Node* root, Node* node) {
  if (!root)
    return false;
  if (root == node)
    return true;
  else return in_tree(root->left, node) || in_tree(root->right, node);
}

Node* first_common_ancestor(Node* root, Node* node0, Node* node1) {
  if (in_tree(root->left, node0) && in_tree(root->left, node1))
    return first_common_ancestor(root->left, node0, node1); 
 else if (in_tree(root->right, node0) && in_tree(root->right, node1))
    return first_common_ancestor(root->right, node0, node1);
  else
    return root;
}

int main() {
  Node* root = new Node(0);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->right = new Node(7);
  root->left->left = new Node(4);
  Node* node0 = new Node(5);
  root->left->right = node0;
  Node* node1 = new Node(6);
  root->left->left->left = node1;
  std::cout << first_common_ancestor(root, node0, node1)->d << std::endl;

}
