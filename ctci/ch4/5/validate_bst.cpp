typedef struct Node {
  int data;
  Node* left;
  Node* right;
} Node;

#include <climits>
bool checkBST(Node* node, int min, int max) {
  if (!node)
    return true;
  if (node->data < min || node->data > max)
    return false;
  return checkBST(node->left, min, node->data - 1) && checkBST(node->right, node->data + 1, max);                
}
bool checkBST(Node* root) {
  return checkBST(root, INT_MIN, INT_MAX);   
}
