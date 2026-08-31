// LeetCode: 830
// Positions of Large Groups

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> largeGroupPositions(std::string s) {
    int low = 0;
    int high = 0;

    int count = 0;

    std::vector<std::vector<int>> result;

    while(high < s.size()) {
      if(s[low] == s[high]) {
        ++count;
        ++high;
      } else {
        if(count >= 3) result.push_back({low, high - 1});
        low = high;
        count = 0;
      }
    }

    if(count >= 3) result.push_back({low, high - 1});

    return result;
  }
};