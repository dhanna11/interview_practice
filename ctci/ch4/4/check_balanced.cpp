#include <iostream>
#include <algorithm>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
} TreeNode;

TreeNode* createBinaryTree(int depth, int data) {
  if (depth == 0) return NULL;
  TreeNode* treeNode = new TreeNode;
  treeNode->data = data;
  treeNode->left = createBinaryTree(depth - 1, 2 * data);
  treeNode->right = createBinaryTree(depth - 1, 2 * data + 1);
  return treeNode;
}

int getHeight(TreeNode *node) {
  if (!node) return 0;
  if (!node->left && !node->right) {
    return 1;
  }
  else {
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
  }
}

bool check_balanced(TreeNode *node) {
  return (abs(getHeight(node->left) - getHeight(node->right)) < 2);
}

int main() {
  TreeNode* balancedTree = createBinaryTree(4,1);
  std::cout << check_balanced(balancedTree) << std::endl; 
  TreeNode* unbalancedTree = new TreeNode;
  unbalancedTree->left = new TreeNode;
  unbalancedTree->left->left = new TreeNode;
  std::cout << check_balanced(unbalancedTree) << std::endl;
}
