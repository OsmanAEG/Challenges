// LeetCode: 138
// Copy List with Random Pointer

#include <unordered_map>

// Definition for a Node.
class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(head == nullptr) return head;

    std::unordered_map<Node*, Node*> node_idx;

    auto it = head;

    Node* copy_head = new Node(head->val);

    auto copy_it = copy_head;

    while(it != nullptr) {
      if(it->next != nullptr) copy_it->next = new Node(it->next->val);

      it = it->next;
      copy_it = copy_it->next;
    }

    it = head;
    copy_it = copy_head;

    while(it != nullptr) {
      node_idx[it] = copy_it;

      it = it->next;
      copy_it = copy_it->next;
    }

    it = head;
    copy_it = copy_head;

    while(it != nullptr) {
      copy_it->random = node_idx[it->random];

      it = it->next;
      copy_it = copy_it->next;
    }

    return copy_head;
  }
};