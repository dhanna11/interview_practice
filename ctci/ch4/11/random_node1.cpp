#include <vector>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <chrono>

typedef struct Node {
  int key;
  int value;
  std::vector<Node*>::size_type index;
  Node* left;
  Node* right;
} Node;

class BST {
public:

  BST() : root(nullptr) {};

  void printBSTPreOrder() {
    printBSTPreOrder(root);
  }

  void printBSTPreOrder(Node* root) {
    if (root != nullptr) {
      std::cout << root->value << std::endl;
      printBSTPreOrder(root->left);
      printBSTPreOrder(root->right);
    }
  }
  
  void insert(int key, int value) {
    if (!root) {
      root = new Node;
      root->key = key;
      root->value = value;
      root->index = 0;
      root->left = nullptr;
      root->right = nullptr;
      nodeVec.push_back(root);
      return;
    }
    
    Node* node = root;
    Node* parent = nullptr;
    while (node != nullptr) {
      parent = node;
      if (node->key > key) {
	node = node->left;
      } else {
	node = node->right;
      }
    }
    if (parent->key > key) {
      parent->left = new Node;
      parent->left->key = key;
      parent->left->value = value;
      parent->left->index = nodeVec.size();
      nodeVec.push_back(parent->left);
    } else {
      parent->right = new Node;
      parent->right->key = key;
      parent->right->value = value;
      parent->right->index = nodeVec.size();
      nodeVec.push_back(parent->right);	
    }    
  }	
  
  Node* find(int key) {
    Node* node = root;
    while (node != nullptr) {
      if (node->key == key) {
	return node;
      }
      else if (node->key > key) {
	node = node->left;
      } else {
	node = node->right;
      }
    }
    return nullptr;    
  }

  void remove(Node* node, Node* parent) {
    if (!node->left && !node->right) {
      deleteNodeFromParent(node, parent);
      deleteNode(node);
      return;
    }
    else if (!node->left && node->right) {
      replaceNodeKeyValue(node, node->right);
      remove(node->right, node);
      return;
    } else if (node->left && !node->right) {
      replaceNodeKeyValue(node, node->left);
      remove(node->left, node);
      return;
    } else {
      Node* predParent;
      Node* pred = InOrderPred(node, &predParent);
      replaceNodeKeyValue(node, pred);
      remove(pred, predParent);
    }
  }

  void deleteNodeFromParent(Node* node, Node* parent) {
    if (parent) {
      if (parent->left == node)
	parent->left = nullptr;
      else
	parent->right = nullptr;
    }
  }
  
  void remove(int key) {
    Node* node = root;
    Node* parent = nullptr;
    while (node != nullptr) {
      if (node->key == key) {
	remove(node, parent);
      }
      else if (node->key > key) {
	parent = node;
	node = node->left;
      }
      else {
	parent = node;
	node = node->right;
      }
    }
  }

  Node* InOrderPred(Node* node, Node** predParent) {
    *predParent = node;
    Node* pred = node->left;
    while (pred->right != nullptr) {
      *predParent = pred;
      pred = pred->right; 
    }
    return pred;
  }
  
  void replaceNodeKeyValue(Node* orig, Node* new_node) {
    orig->key = new_node->key;
    orig->value = new_node->value;
  }

  // move last element into deleted element position
  void deleteNode(Node* node) {
    if (node->index != nodeVec.size() -1) {
      nodeVec.back()->index = node->index;
      nodeVec[node->index] = nodeVec.back();
    }
    nodeVec.pop_back();
    delete node;
  }
  
  Node* getRandomNode() {
    std::default_random_engine generator;
    typedef std::chrono::high_resolution_clock myclock;
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    generator.seed(seed);
    std::uniform_int_distribution<int> distribution(0, nodeVec.size() - 1);
    return nodeVec.at(distribution(generator));
  }

  Node* root;
  std::vector<Node*> nodeVec;
  int size;
};

int main() {
  BST bst;
  bst.insert(2,2);
  bst.insert(1,1);
  bst.insert(3,3);
  bst.insert(4,4);
  bst.insert(5,5);
  std::cout << bst.getRandomNode()->value << std::endl;
}
