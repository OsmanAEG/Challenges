// LeetCode: 143
// Reorder List

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
  void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return;

    ListNode* next = head;
    ListNode* end  = head;

    int size = 0;

    while(end != nullptr) {
      ++size;
      end = end->next;
    }

    for(int i = 0; i < (size-1)/2; ++i) {
      ListNode* prev = next;

      while(prev->next->next != nullptr) {
        prev = prev->next;
      }

      end = prev->next;
      prev->next = nullptr;

      end->next = next->next;
      next->next = end;

      next = end->next;
    }
  }
};