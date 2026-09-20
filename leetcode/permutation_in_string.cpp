// LeetCode: 567
// Permutation in String

#include <algorithm>
#include <string>

class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    if(s2.size() < s1.size()) return false;

    std::sort(s1.begin(), s1.end());

    int low = 0;
    int high = 0;

    std::string permutation = "";

    while(high < s2.size()) {
      permutation += s2[high];

      if(high - low + 1 == s1.size()) {
        auto sorted_permutation = permutation;
        std::sort(sorted_permutation.begin(), sorted_permutation.end());

        if(sorted_permutation == s1) return true;

        permutation.erase(permutation.begin());
        ++low;
      }

      ++high;
    }

    return false;
  }
};