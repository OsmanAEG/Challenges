// LeetCode: 338
// Counting Bits

#include <vector>

class Solution {
public:
  std::vector<int> countBits(int n) {
    std::vector<int> result(n + 1, 0);

    for(int i = 0; i <= n; ++i) {
      int num = i;

      while(num > 0) {
        result[i] += num % 2;
        num /= 2;
      }
    }

    return result;
  }
};