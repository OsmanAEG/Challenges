// LeetCode: 141
// Linked List Cycle

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    if(head == nullptr) return false;

    while(fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if(slow == fast) return true;
    }

    return false;
  }
};