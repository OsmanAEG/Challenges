// LeetCode: 202
// Happy Number

#include <set>

class Solution {
public:
  int transform_num(int n) {
    int result = 0;

    while(n > 0) {
      int r = n%10;
      result += r*r;
      n = n/10;
    }

    return result;
  }

  bool isHappy(int n) {
    std::set<int> nums;

    while(n != 1) {
      if(nums.find(n) != nums.end()) {
        return false;
      }

      nums.insert(n);
      n = transform_num(n);
    }

    return true;
  }
};