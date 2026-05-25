// LeetCode: 125
// Valid Palindrome

#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string result;
    for(const auto& c : s) {
      if(std::isalnum(c)) result += std::tolower(c);
    }

    int low = 0;
    int high = result.size() - 1;

    while(low < high) {
      if(result[low] != result[high]) return false;
      ++low;
      --high;
    }

    return true;
  }
};