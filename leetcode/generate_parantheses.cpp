// LeetCode: 22
// Generate Parantheses

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> combos;

  bool is_valid(std::string input) {
    std::stack<char> check;

    for(const auto& c : input) {
      if(c == ')') {
        if(check.empty()) return false;
        else check.pop();
      } else {
        check.push(c);
      }
    }

    if(check.empty()) return true;
    else return false;
  }

  void create_combos(std::string combo, int n) {
    if(combo.size() == 2*n) {
      combos.push_back(combo);
      return;
    } else {
      create_combos(combo + ')', n);
      create_combos(combo + '(', n);
    }
  }

  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    create_combos("", n);

    for(const auto& combo : combos) {
      if(is_valid(combo)) result.push_back(combo);
    }

    return result;
  }
};