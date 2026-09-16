// LeetCode 3:
// Longest Substring Without Repeating Characters

#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::size_t result = 0;

    std::size_t low = 0;
    std::size_t high = 0;

    std::unordered_set<char> my_set;

    while(high < s.size()) {
      if(my_set.find(s[high]) == my_set.end()) {
        my_set.insert(s[high]);
        result = std::max(my_set.size(), result);
        ++high;
      } else {
        while(low <= high) {
          if(s[low] == s[high]) {
            my_set.erase(s[low]);
            ++low;
            break;
          } else {
            my_set.erase(s[low]);
            ++low;
          }
        }
      }
    }

    return result;
  }
};