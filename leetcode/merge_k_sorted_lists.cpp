// LeetCode: 23
// Merge k Sorted Lists

#include <queue>
#include <vector>

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
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* result = nullptr;

    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for(const auto& list : lists) {
      auto head = list;

      while(head != nullptr) {
        min_heap.push(head->val);
        head = head->next;
      }
    }

    if(!min_heap.empty()) {
      result = new ListNode(min_heap.top());
      min_heap.pop();
    }

    auto head = result;

    while(!min_heap.empty()) {
      auto next = new ListNode(min_heap.top());
      min_heap.pop();

      head->next = next;
      head = next;
    }

    return result;
  }
};