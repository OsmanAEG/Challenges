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
  ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;
    if(head->next == nullptr) return head;

    auto tail = head;
    auto next = head->next;

    while(next != nullptr) {
      if(tail->val == next->val) {
        next = next->next;
        tail->next = next;
      } else {
        tail = next;
        next = next->next;
      }
    }

    return head;
  }
};