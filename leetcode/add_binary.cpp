// LeetCode: 67
// Add Binary

#include <algorithm>
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int idx_a = a.size() - 1;
    int idx_b = b.size() - 1;

    int carry = 0;

    std::string result;

    while(idx_a >= 0 || idx_b >= 0 || carry != 0) {
      int sum = carry;

      if(idx_a >= 0) {
        sum += a[idx_a] - '0';
        --idx_a;
      }

      if(idx_b >= 0) {
        sum += b[idx_b] - '0';
        --idx_b;
      }

      result.push_back('0' + sum % 2);

      carry = sum / 2;
    }

    std::reverse(result.begin(), result.end());

    return result;
  }
};