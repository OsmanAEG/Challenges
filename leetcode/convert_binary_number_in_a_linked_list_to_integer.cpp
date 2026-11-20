// LeetCode: 1290
// Convert Binary Number in a Linked List to Integer

#include <cmath>
#include <string>

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
  int binary_to_decimal(std::string binary_str) {
    int num = 0;
    int power = binary_str.size() - 1;

    for(const auto& digit : binary_str) {
      if(digit == '1') num += std::pow(2, power);
      --power;
    }

    return num;
  }

  int getDecimalValue(ListNode* head) {
    std::string binary_str = "";

    while(head != nullptr) {
      binary_str += head->val + '0';
      head = head->next;
    }

    return binary_to_decimal(binary_str);
  }
};