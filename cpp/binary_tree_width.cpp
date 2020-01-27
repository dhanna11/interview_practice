#include <utility>
#include <iostream>

struct Node {
  Node* left;
  Node* right;
  int val;
};

std::pair<int, int> getMinMax(Node* root, int net) {
  if (!root)
    return std::pair<int,int> (0,0);

  std::pair<int, int> leftMinMax = getMinMax(root->left, net -1);
  std::pair<int, int> rightMinMax = getMinMax(root->right, net + 1);

  int min = std::min(std::min(leftMinMax.first, rightMinMax.first), net);
  int max = std::max(std::max(leftMinMax.second, rightMinMax.second), net);
  
  return std::make_pair(min, max);
}

int get_binary_tree_width(Node* root) {
  std::pair<int, int> minMax = getMinMax(root, 0);
  return -minMax.first + minMax.second;
}

int main () {
  Node* root = new Node;
  root->left = new Node;
  root->left->left = new Node;
  root->left->right = new Node;
  root->right = new Node;
  root->right->right = new Node;
  root->right->left = new Node;
  std::cout << get_binary_tree_width(root) << std::endl;

  return 0;

}
