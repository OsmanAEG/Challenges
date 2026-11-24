// LeetCode: 856
// Score of Parantheses

#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
  int scoreOfParentheses(std::string s) {
    std::stack<int> scores;

    int score = 0;

    for(const auto& c : s) {
      if(c == '(') {
        scores.push(score);
        score = 0;
      } else {
        score = scores.top() + std::max(1, 2 * score);
        scores.pop();
      }
    }

    return score;
  }
};