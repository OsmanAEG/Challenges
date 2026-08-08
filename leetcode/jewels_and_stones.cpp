// LeetCode: 771
// Jewels and Stones

#include <set>
#include <string>

class Solution {
public:
  int numJewelsInStones(std::string jewels, std::string stones) {
    int sum = 0;
    std::set<char> jewel;

    for(int i = 0; i < jewels.size(); ++i) {
      jewel.insert(jewels[i]);
    }

    for(const auto& stone : stones) {
      if(jewel.find(stone) != jewel.end()) ++sum;
    }

    return sum;
  }
};