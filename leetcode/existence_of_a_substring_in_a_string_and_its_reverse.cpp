// LeetCode: 3083
// Existence of a Substring in a String and Its Reverse

#include <unordered_set>
#include <string>

class Solution {
public:
  bool isSubstringPresent(std::string s) {
    if(s.size() < 2) return false;

    std::unordered_set<std::string> forward_set;
    std::unordered_set<std::string> reverse_set;

    std::string forward_str = "";
    std::string reverse_str = "";

    forward_str += s[0];
    forward_str += s[1];

    reverse_str += s[s.size() - 1];
    reverse_str += s[s.size() - 2];

    forward_set.insert(forward_str);
    reverse_set.insert(reverse_str);

    for(int i = 2; i < s.size(); ++i) {
      forward_str.erase(forward_str.begin());
      reverse_str.erase(reverse_str.begin());

      forward_str += s[i];
      reverse_str += s[s.size() - i - 1];

      forward_set.insert(forward_str);
      reverse_set.insert(reverse_str);
    }

    for(const auto& str : forward_set) {
      if(reverse_set.find(str) != reverse_set.end()) return true;
    }

    return false;
  }
};