// LeetCode: 2778
// Sum of Squares of Special Elements

#include <vector>

class Solution {
public:
  int sumOfSquares(std::vector<int>& nums) {
    int result = 0;

    for(int i = 1; i <= nums.size(); ++i) {
      if(nums.size()%i == 0) result += nums[i-1]*nums[i-1];
    }

    return result;
  }
};