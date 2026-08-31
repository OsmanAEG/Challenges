// LeetCode: 19
// Remove Nth Node From End of List

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;
    auto it = head;

    int head_size = 0;

    while(it != nullptr) {
      ++head_size;
      it = it->next;
    }

    it = head;

    if(head_size == n) return head->next;

    for(int i = 0; i < head_size - n - 1; ++i) {
      it = it->next;
    }

    if(it == nullptr) return head;
    if(it->next == nullptr) return head;

    it->next = it->next->next;

    return head;
  }
};