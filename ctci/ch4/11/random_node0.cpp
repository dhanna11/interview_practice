#include <iostream>
#include <assert.h>
#include <random>
#include <chrono>
typedef struct Node {
  Node(int key) : key(key), size(1), left(nullptr), right(nullptr) {};
  int key;
  int size;
  Node* left;
  Node* right;
} Node;

class BST {
public:
  BST() : root(nullptr) {};

  void print() {
    printPreOrder(root);
    std::cout << std::endl;
  }

  void insert(int key) {
    insert(root, key);
  }

  Node* find(int key) {
    return find(root, key);
  }

  void remove(int key) {
    remove(root, nullptr, key);
  }

  Node* getRandomNode() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> dist(0, root->size -1);
    int roll = dist(generator);
    return getRandomNode(root, roll);
  }
  
private:  
  void printPreOrder(Node* node) {
    if (node != nullptr) {
      std::cout << "key: " << node->key << " size: " << node->size << std::endl;
      printPreOrder(node->left);
      printPreOrder(node->right);
    }
  }
    
  void insert(Node*& node, int key) {
    if (!node) {
      node = new Node(key);
      return;
    } else if (node->key == key) {
      return;
    }
    node->size++;
    if (node->key > key) {
      insert(node->left, key);
    } else {
      assert(node->key < key);
      insert(node->right, key);
    }	      
  }
  
  Node* find(Node* node, int key) {
    if (!node)
      return nullptr;
    if (node->key == key)
      return node;
    else if (node->key > key)
      return find(node->left, key);
    else
      return find(node->right, key);
  }
  
  void remove(Node* node, Node* parent, int key) {
    if (!node)
      return;
    node->size--;
    if (node->key == key)
      removeNode(node, parent);
    else if (node->key > key)
      remove(node->left, node, key);
    else
      remove(node->right, node, key);
  }

  void removeNode(Node* node, Node* parent) {
    assert(node != nullptr);
    if (!node->left && !node->right) {
      if (parent != nullptr) {
	if (parent->left == node) 
	  parent->left = nullptr;
	else
	  parent->right = nullptr;
      }
      delete node;
    }
    else if (!node->left && node->right) {
      node->key = node->right->key;
      removeNode(node->right, node);
    } else if (node->left && !node->right) {
      node->key = node->left->key;
      removeNode(node->left, node);
    } else {
      Node* predParent;
      Node* pred = InOrderPred(node, &predParent);
      assert(pred != nullptr);
      node->key = pred->key;
      removeNode(pred, predParent);
    }
  }

  Node* InOrderPred(Node* node, Node** predParent) {
    *predParent = node;
    node = node->left;
    while (node->right != nullptr) {
      *predParent = node;
      node = node->right;
    }
    return node;
  }

  Node* getRandomNode(Node* node, int roll) {
    int leftSize = node->left ? node->left->size : 0;
    if (roll == node->size - 1) {
      return node;
    } else if (roll < leftSize)
      return getRandomNode(node->left, roll);
    else
      return getRandomNode(node->right, roll %  node->right->size);
  }
  
  Node* root;

};

int main() {

  BST bst;
  bst.insert(2);
  bst.insert(1);
  bst.insert(3);
  bst.insert(-1);
  bst.insert(4);
  bst.insert(-2);
  std::cout << bst.getRandomNode()->key << std::endl;
}
