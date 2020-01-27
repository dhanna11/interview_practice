#include <vector>
#include <iostream>

struct TreeNode {
  TreeNode(int data) : data(data), left(NULL), right(NULL) {}
  int data;
  TreeNode *left;
  TreeNode *right;
};

struct Node {
  Node (int data) : data(data), next(NULL) {}
  int data;
  Node* next;
  
  void addToEnd (int data) {
    Node* temp = this;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new Node(data);
  }
};

void make_lists(TreeNode* treeNode, int depth, std::vector<Node*> &linkedListList) {
  if (treeNode != NULL) {
    
    if (linkedListList.size() < (depth + 1)) {
      linkedListList.resize(depth + 1);
    }
    Node *linkedList = linkedListList.at(depth);
    if (linkedList == NULL) {
      linkedListList[depth] = new Node(treeNode->data);
    }
    else {
      linkedList->addToEnd(treeNode->data);
    }
    make_lists(treeNode->left, depth + 1, linkedListList);
    make_lists(treeNode->right,depth + 1, linkedListList);
  }
}
  

std::vector<Node*> list_of_depths(TreeNode* root) {
  std::vector<Node*> linkedListList;
  make_lists(root, 0, linkedListList);
  return linkedListList;
}

int main() {
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(5);
  root->right = new TreeNode(2);
  root->left->right = new TreeNode(10);
  root->left->left = new TreeNode(8);
  root->right->right = new TreeNode(9);
  root->right->left = new TreeNode(3);
  std::vector<Node*> nodes = list_of_depths(root);
  for (Node *node : nodes) {
    Node *temp = node;
    while (temp != NULL) {
      std::cout << temp->data;
      temp = temp->next;
    }
    std::cout << "\n";
  }
}
