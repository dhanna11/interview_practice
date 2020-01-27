#include <iostream>
#include <map>
#include <vector>

typedef struct Node {
  int key;
  int value;
  Node *next;
  Node *prev;

  Node(int key, int value) : key(key), value(value), next(NULL), prev(NULL) {}
} Node;

class LRUCache {
public:
  LRUCache(int capacity)
      : capacity(capacity), num_elements(0), head(NULL), tail(NULL) {}

  int get(int key) {
    Node *outNode;
    if (in_cache(key, &outNode)) {
      make_mru(outNode);
      return outNode->value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    Node *outNode;
    if (in_cache(key, &outNode)) {
      make_mru(outNode);
      outNode->value = value;
    } else if (capacity == num_elements) {
      evict_and_replace(key, value);
    } else {
      alloc_and_add_to_cache(key, value);
    }
  }

private:
  bool in_cache(int key, Node **outNode) {
    auto it = node_map.find(key);
    if (it != node_map.end()) {
      *outNode = it->second;
      return true;
    }
    return false;
  }

  void make_mru(Node *node) {
    removeNode(node);
    prependNodeToHead(node);
  }

  void evict_and_replace(int key, int value) {
    node_map.erase(tail->key);
    node_map[key] = tail;
    tail->key = key;
    tail->value = value;
    make_mru(tail);
  }

  void alloc_and_add_to_cache(int key, int value) {
    Node *node = new Node(key, value);
    node_map[key] = node;
    prependNodeToHead(node);
  }

  Node *removeNode(Node *node) {
    // singleton node
    if (!node->next && !node->prev) {
      head = NULL;
      tail = NULL;
    }
    // tail node
    else if (!node->next && node->prev) {
      node->prev->next = NULL;
      tail = node->prev;
      // head node
    } else if (node->next && !node->prev) {
      node->next->prev = NULL;
      head = node->next;
      //
    } else {
      node->next->prev = node->prev;
      node->prev->next = node->next;
    }
    num_elements--;
    node->prev = NULL;
    node->next = NULL;
    return node;
  }

  void prependNodeToHead(Node *node) {
    if (!head && !tail) {
      head = node;
      tail = node;
      node->prev = NULL;
      node->next = NULL;
    } else {
      head->prev = node;
      node->next = head;
      node->prev = NULL;
      head = node;
    }
    num_elements++;
  }

  int capacity;
  int num_elements;
  Node *head;
  Node *tail;
  std::unordered_map<int, Node *> node_map;
};

int main() {
  std::cout << "Hello World!" << std::endl;
  LRUCache cache = LRUCache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  std::cout << cache.get(1) << std::endl; // returns 1
  cache.put(3, 3);                        // evicts key 2
  std::cout << cache.get(2) << std::endl; // returns -1 (not found)
  cache.put(4, 4);                        // evicts key 1
  std::cout << cache.get(1) << std::endl; // returns -1 (not found)
  std::cout << cache.get(3) << std::endl; // returns 3
  std::cout << cache.get(4) << std::endl; // returns 4
  return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
