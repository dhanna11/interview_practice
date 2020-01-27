#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

typedef struct TreeNode {
  int data;
  TreeNode* right;
  TreeNode* left;
  friend std::ostream& operator<<(std::ostream& os, const TreeNode& treeNode);
} TreeNode;

std::ostream& operator<<(std::ostream& os, const TreeNode& treeNode) {
  return os << treeNode.data << ' ';
}

template <class T>
class LinkedListNode{
public:
  LinkedListNode(T val) : val(val) {}
  
  void appendToTail(T val) {
    auto node = this;
    while (node->next !=  NULL) {
      node = node->next;      
    }
    node->next = new LinkedListNode(val);
    return;
  }

  std::string printList() {
    std::ostringstream os;
    auto node = this;
    os << " LL: ";
    while (node != NULL) {
      os << *node->val;
      node = node->next;
    }
    return os.str();
  }
  T val;
  LinkedListNode* next;
};

TreeNode* createBinaryTree(int depth, int data) {
  if (depth == 0) return NULL;
  TreeNode* treeNode = new TreeNode;
  treeNode->data = data;
  treeNode->left = createBinaryTree(depth - 1, 2 * data);
  treeNode->right = createBinaryTree(depth - 1, 2 * data + 1);
  return treeNode;

}

void map_of_depths(TreeNode* node, int depth, std::map<int, LinkedListNode<TreeNode*>>& map) {
  if (node != NULL) {
    auto it = map.find(depth);
    if (it != map.end()) {
      it->second.appendToTail(node);
    } else {
      map.emplace(depth, node);
    }
    map_of_depths(node->left, depth + 1, map);
    map_of_depths(node->right, depth + 1, map);
  }
}
void inOrderTraversal(TreeNode* node) {
  if (node != NULL) {
    inOrderTraversal(node->left);
    std::cout << node->data << std::endl;
    inOrderTraversal(node->right);
  }
}

int main() {
  TreeNode* treeNode =  createBinaryTree(4,1);
  inOrderTraversal(treeNode);
  std::map<int, LinkedListNode<TreeNode*>> map;
  map_of_depths(treeNode, 0, map);
  for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << "Depth:" << it->first;
    std::cout << it->second.printList() << std::endl;
  }  
}
