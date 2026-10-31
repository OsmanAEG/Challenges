// LeetCode: 25
// Reverse Nodes in k Group

#include <algorithm>
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    std::vector<std::vector<ListNode*>> groups;
    auto it = head;

    while(it != nullptr) {
      std::vector<ListNode*> group;

      for(int i = 0; i < k; ++i) {
        if(it == nullptr) break;
        group.push_back(it);
        it = it->next;
      }

      groups.push_back(group);
    }

    for(auto& group : groups) {
      if(group.size() < k) continue;

      std::reverse(group.begin(), group.end());

      for(int i = 0; i < group.size() - 1; ++i) {
        group[i]->next = group[i+1];
      }
    }

    for(int i = 0; i < groups.size() - 1; ++i) {
      const auto n = groups[i].size();
      groups[i][n - 1]->next = groups[i + 1][0];
    }

    groups.back().back()->next = nullptr;

    it = groups[0][0];

    return it;
  }
};