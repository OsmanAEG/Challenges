// LeetCode: 424
// Longest Repeating Character Replacement

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    int low = 0;
    int high = 0;

    int max_count = 0;
    int result = 0;

    std::unordered_map<char, int> nums_map;

    while(high < s.size()) {
      ++nums_map[s[high]];

      max_count = std::max(max_count, nums_map[s[high]]);

      while(high - low + 1 - max_count > k) {
        --nums_map[s[low]];
        ++low;
      }

      result = std::max(result, high - low + 1);

      ++high;
    }

    return result;
  }
};