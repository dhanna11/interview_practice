#include <memory>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>

unsigned int hash_fn(unsigned int x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x;
}

struct Node {
  Node(int val, int idx) : val(val), idx(idx), next(nullptr), prev(nullptr) {}
  int getIdx() {
    return idx;
  }
  void setIdx(int idx) {
    this->idx = idx;
  }
  int val;
  int idx;
  Node* next;
  Node* prev;
};


class LinkedList {
public:
  
  LinkedList() {
    head = nullptr;
  }

  ~LinkedList() {
    while (head != nullptr) {
      Node* next = head->next;
      delete head;
      head = next;
    }
  }

  LinkedList(const LinkedList&)=delete;
  LinkedList& operator=(const LinkedList&) =delete;
  LinkedList(LinkedList &&) = default;
  
  void insert(int val, int idx) {
    Node* node = new Node(val, idx);
    if (this->head != nullptr)
      this->head->prev = node;
    
    node->next = this->head;
    this->head = node;
  }

  bool contains(int val) {
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
      if (temp->val == val)
	return true;
    }
    return false;
  }

  Node* getNode(int val) {
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
      if (temp->val == val)
	return temp;
    }
    return nullptr;
  }

  void remove(Node* node) {
    if (node->prev != nullptr)
      node->prev->next = node->next;
    else head = node->next;
    
    if (node->next != nullptr)
      node->next->prev = node->prev;

    delete node;
  }
  
private:
  Node* head;
};
  
class RandomizedSet {
public:
  RandomizedSet() {
    nbuckets = 31;
    for (int i = 0; i < 31; i++) {
      buckets.emplace_back();
    }
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
  }

  LinkedList &select_chain(int val) {
    std::size_t hash = hash_fn(val);
    std::size_t bucket_idx = hash % nbuckets;
    std::cout << "bucket_idx" << bucket_idx << std::endl;
    return buckets.at(bucket_idx);  
  }
  
  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (select_chain(val).contains(val))
      return false;
    keys.emplace_back(val); 
    select_chain(val).insert(val, keys.size() -1);
    return true;
  }
    
  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (!select_chain(val).contains(val))
      return false;

    for (auto key : keys)
      std::cout << key << std::endl;
    int node_idx = select_chain(val).getNode(val)->getIdx();
    select_chain(keys.back()).getNode(keys.back())->setIdx(node_idx);
    keys[node_idx] = keys.back();
    keys.pop_back();
    select_chain(val).remove(select_chain(val).getNode(val));

    for (auto key : keys)
      std::cout << key;

    return true;
  }
    
  /** Get a random element from the set. */
  int getRandom() {
    std::uniform_int_distribution<int> dist(0, keys.size() - 1);
    return keys.at(dist(generator));
  }
    
  std::vector<int> keys;
  std::vector<LinkedList> buckets;
  int nbuckets;
  std::default_random_engine generator;
};
