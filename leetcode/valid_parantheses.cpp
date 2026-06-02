// LeetCode: 20
// Valid Parantheses

#include<stack>
#include<string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> parantheses;

    for(const auto& c : s) {
      if(c == '(' || c == '[' || c == '{') {
        parantheses.push(c);
      } else {
        if(parantheses.empty()) return false;
        if(c == ')' && parantheses.top() != '(') return false;
        if(c == ']' && parantheses.top() != '[') return false;
        if(c == '}' && parantheses.top() != '{') return false;

        parantheses.pop();
      }
    }

    if(!parantheses.empty()) return false;

    return true;
  }
};