// LeetCode: 206
// Reverse Linked List

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
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return head;
    auto step1 = head;
    if(step1->next == nullptr) return head;
    auto step2 = head->next;

    while(step2 != nullptr) {
      auto tmp = step2->next;

      step2->next = step1;

      step1 = step2;
      step2 = tmp;
    }

    head->next = step2;

    return step1;
  }
};