// LeetCode: 14
// Longest Common Prefix

#include <algorithm>
#include <climits>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string prefix = "";
    int i_max = INT_MAX;

    for(const auto& str : strs) {
      i_max = std::min(i_max, static_cast<int>(str.size()));
    }

    for(int i = 0; i < i_max; ++i) {
      bool is_common = true;

      char letter = strs[0][i];

      for(const auto& str : strs) {
        if(str[i] != letter) is_common = false;
      }

      if(is_common == true) prefix += letter;
      else break;
    }

    return prefix;
  }
};