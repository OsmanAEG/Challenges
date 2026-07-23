// LeetCode: 392
// Is Subsequence

#include <stack>
#include <string>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    std::stack<char> seq;

    for(int i = s.size() - 1; i >= 0; --i){
      seq.push(s[i]);
    }

    int i = 0;

    while(i < t.size() && seq.empty() == false) {
      if(t[i] == seq.top()) seq.pop();
      ++i;
    }

    if(seq.empty()) return true;
    return false;
  }
};