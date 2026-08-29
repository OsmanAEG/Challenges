// LeetCode: 876
// Middle of the Linked List

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
  ListNode* middleNode(ListNode* head) {
    int list_length = 0;

    auto it = head;

    while(it != nullptr) {
      ++list_length;
      it = it->next;
    }

    it = head;

    const int step_max = list_length/2;;
    int steps = 0;

    while(steps < step_max) {
      it = it->next;
      ++steps;
    }

    return it;
  }
};