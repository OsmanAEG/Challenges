// LeetCode: 21
// Merge Two Sorted Lists

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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    auto list_1_it = list1;
    auto list_2_it = list2;

    if(list_1_it == nullptr) return list_2_it;
    if(list_2_it == nullptr) return list_1_it;

    ListNode *list_it;
    ListNode *list_head;

    if(list_1_it->val > list_2_it->val) {
      list_it = list_2_it;
      list_2_it = list_2_it->next;
    } else {
      list_it = list_1_it;
      list_1_it = list_1_it->next;
    }

    list_head = list_it;

    while(list_1_it != nullptr && list_2_it != nullptr) {
      if(list_1_it->val > list_2_it->val) {
        list_it->next = list_2_it;
        list_2_it = list_2_it->next;
      } else {
        list_it->next = list_1_it;
        list_1_it = list_1_it->next;
      }

      list_it = list_it->next;
    }

    while(list_1_it != nullptr) {
      list_it->next = list_1_it;
      list_1_it = list_1_it->next;

      list_it = list_it->next;
    }

    while(list_2_it != nullptr) {
      list_it->next = list_2_it;
      list_2_it = list_2_it->next;

      list_it = list_it->next;
    }

    return list_head;
  }
};