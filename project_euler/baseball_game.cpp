// LeetCode: 682
// Baseball Game

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int calPoints(std::vector<std::string>& operations) {
    int score = 0;
    std::stack<int> record;

    for(const auto& op : operations) {
      if(op == "+") {
        const auto num1 = record.top();
        record.pop();
        const auto num2 = record.top();
        record.pop();

        record.push(num2);
        record.push(num1);
        record.push(num1 + num2);
      } else if(op == "D") {
        record.push(2*record.top());
      } else if(op == "C") {
        record.pop();
      } else {
        record.push(std::stoi(op));
      }
    }

    while(!record.empty()) {
      score += record.top();
      record.pop();
    }

    return score;
  }
};