// LeetCode: 3908
// Valid Digit Number

#include <string>

class Solution {
public:
  bool validDigit(int n, int x) {
    const auto n_str  = std::to_string(n);
    const char x_char = x + '0';

    if(n_str[0] == x_char) return false;

    bool has_digit = false;

    for(const auto& digit : n_str) {
      if(digit == x_char) {
        has_digit = true;
        break;
      }
    }

    if(has_digit) return true;

    return false;
  }
};