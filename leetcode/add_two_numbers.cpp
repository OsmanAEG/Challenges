// LeetCode: 2
// Add Two Numbers

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode;

    auto tail = head;

    int remainder = 0;

    while(true) {
      int sum = l1->val + l2->val + remainder;

      if(sum >= 10) {
        tail->val = sum - 10;
        remainder = 1;
      } else {
        tail->val = sum;
        remainder = 0;
      }

      l1 = l1->next;
      l2 = l2->next;

      if(l1 == nullptr || l2 == nullptr) break;

      ListNode* node = new ListNode;
      tail->next = node;
      tail = tail->next;
    }

    if(l1 != nullptr) {
      ListNode* node = new ListNode;
      tail->next = node;
      tail = tail->next;

      while(true) {
        int sum = l1->val + remainder;

        if(sum >= 10) {
          tail->val = sum - 10;
          remainder = 1;
        } else {
          tail->val = sum;
          remainder = 0;
        }

        l1 = l1->next;

        if(l1 == nullptr) break;

        ListNode* node = new ListNode;
        tail->next = node;
        tail = tail->next;
      }
    }

    if(l2 != nullptr) {
      while(true) {
        int sum = l2->val + remainder;

        if(sum >= 10) {
          tail->val = sum - 10;
          remainder = 1;
        } else {
          tail->val = sum;
          remainder = 0;
        }

        l2 = l2->next;

        if(l2 == nullptr) break;

        ListNode* node = new ListNode;
        tail->next = node;
        tail = tail->next;
      }
    }

    if(remainder != 0) {
      ListNode* node = new ListNode;
      node ->val = 1;
      tail->next = node;
      tail = tail->next;
    }

    return head;
  }
};