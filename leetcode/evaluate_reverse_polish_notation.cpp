// LeetCode: 150
// Evaluate Reverse Polish Notation

#include <set>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int operation(int num1, int num2, std::string operand) {
    if(operand == "+") return num1 + num2;
    else if(operand == "-") return num1 - num2;
    else if(operand == "*") return num1 * num2;
    else return num1 / num2;
  }

  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> values;

    std::set<std::string> operands = {"+", "-", "/", "*"};

    for(const auto& s : tokens) {
      if(operands.find(s) != operands.end()) {
        const auto num2 = values.top();
        values.pop();
        const auto num1 = values.top();
        values.pop();
        const auto result = operation(num1, num2, s);
        values.push(result);
      } else {
        values.push(std::stoi(s));
      }
    }

    return values.top();
  }
};