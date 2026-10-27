// LeetCode: 504
// Base 7

#include <algorithm>
#include <string>

class Solution {
public:
  std::string convertToBase7(int num) {
    if(num == 0) return "0";

    long long n = num;
    bool negative = false;

    if(n < 0) {
      negative = true;
      n *= -1;
    }

    std::string result;

    while(n > 0) {
      result += std::to_string(n % 7);
      n /= 7;
    }

    if(negative) result += '-';

    std::reverse(result.begin(), result.end());

    return result;
  }
};