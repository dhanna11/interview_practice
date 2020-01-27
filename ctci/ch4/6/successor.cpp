#include <iostream>

typedef struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;
} Node;

void insert_bst(Node* root, int val) {
  if (root->data > val) {
    if (root->left) 
      insert_bst(root->left, val);
    else {
      root->left = new Node;
      root->left->data = val;
      root->left->parent = root;
    }
  } else {
    if (root->right)
      insert_bst(root->right, val);
    else {
      root->right = new Node;
      root->right->data = val;
      root->right->parent = root;
    }
  }
}

void inOrderTraversal(Node* node) {
  if (node != NULL) {
    inOrderTraversal(node->left);
    std::cout << node->data;
    inOrderTraversal(node->right);
  }
}

Node* getLeftMostNode(Node* node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

Node* successor(Node* node) {
  if (!node->parent) {
    return NULL;
  } else if (node->right) {
    return getLeftMostNode(node->right);
  } else {
    for (Node* temp = node->parent; temp != NULL; temp = temp->parent) {
      if (temp->data > node->data)
	return temp;
    }
  }
  return NULL;  
}

int main() {
  Node* root = new Node;
  root->data = 10;
  insert_bst(root, 5);
  insert_bst(root, 25);
  insert_bst(root, 3);
  insert_bst(root, 7);
  insert_bst(root, 23);
  insert_bst(root, 30);
  insert_bst(root, 2);
  insert_bst(root, 4);
  insert_bst(root, 6);
  insert_bst(root, 9);
  insert_bst(root, 20);
  insert_bst(root, 24);
  insert_bst(root, 32);
  insert_bst(root, 8);
  insert_bst(root, 18);
  insert_bst(root, 21);
  insert_bst(root, 31);
  insert_bst(root, 33);
 
  //inOrderTraversal(root);
  Node* temp = successor(root->right->right->right);
  std::cout << temp->data;
}
