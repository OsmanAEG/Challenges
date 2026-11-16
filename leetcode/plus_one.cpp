// LeetCode: 66
// Plus One

#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int remainder = 1;

    for(int i = digits.size() - 1; i >= 0; --i) {
      int sum_i = digits[i] + remainder;
      digits[i] = sum_i;

      if(sum_i >= 10) {
        digits[i] -= 10;
        remainder = 1;
      } else {
        remainder = 0;
        break;
      }
    }

    if(remainder != 0) {
      digits.insert(digits.begin(), remainder);
      remainder = 0;
    }

    return digits;
  }
};