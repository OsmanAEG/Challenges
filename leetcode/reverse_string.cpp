// LeetCode: 344
// Reverse String

#include <vector>

class Solution {
public:
  void reverseString(std::vector<char>& s) {
    int low = 0;
    int high = s.size() - 1;

    while(low < high) {
      const auto c_low = s[low];
      const auto c_high = s[high];

      s[low] = c_high;
      s[high] = c_low;

      ++low;
      --high;
    }
  }
};