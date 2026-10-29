// LeetCode: 191
// Number of One Bits

#include <bitset>
#include <string>

class Solution {
public:
  int hammingWeight(int n) {
    int num_ones = 0;
    const auto binary_str = std::bitset<32>(n).to_string();

    for(const auto& c : binary_str) {
      if(c == '1') ++num_ones;
    }

    return num_ones;
  }
};