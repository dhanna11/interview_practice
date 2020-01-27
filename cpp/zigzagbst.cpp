#include <iostream>
#include <stack>
#include <map>
#include <queue>

struct Node {
  Node (int val) : left(nullptr), right(nullptr), val(val) {}
  struct Node* left;
  struct Node* right;
  int val;
};

void flushStack(std::stack<Node*> & s) {
  while (!s.empty()) {
    std::cout << s.top()->val;
    s.pop();
  }
}

void zigzag(Node* root) {
  if (!root)
    return;

  std::map<Node*, int> dist;
  std::queue<Node*> q;
  std::stack<Node*> s;
  int currentDist = 0;
  q.push(root);
  dist[root] = 0;

  while (!q.empty()) {
    Node *n = q.front();
    q.pop();
    if (dist[n] != currentDist) {
      flushStack(s);
      currentDist = dist[n];
    }
    if (currentDist % 2 == 1)
      s.push(n);
    else
      std::cout << n->val;

    if (n->left) {
      dist[n->left] = currentDist + 1;
      q.push(n->left);
    }
    if (n->right) {
      dist[n->right] = currentDist + 1;
      q.push(n->right);
    }
  }
  flushStack(s);
}

int main() {
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->right = new Node(7);
	root->right->left = new Node(6);
	root->left->right = new Node(5);
	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->right->left->left = new Node (10);
	zigzag(root);
}
