// LeetCode: 2807
// Insert Greatest Common Divisors in Linked List

#include <algorithm>

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
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head == nullptr) return head;
    if(head->next == nullptr) return head;

    auto tail = head;
    auto next = head->next;

    while(next != nullptr) {
      const auto val_tail = tail->val;
      const auto val_next = next->val;

      int max_val = std::max(val_tail, val_next);

      int gcd = 0;

      for(int i = max_val; i > 0; --i) {
        if(val_tail%i == 0 && val_next%i == 0){
          gcd = i;
          break;
        }
      }

      ListNode* gcd_node = new ListNode(gcd);

      tail->next = gcd_node;
      gcd_node->next = next;

      tail = next;
      next = next->next;
    }

    return head;
  }
};