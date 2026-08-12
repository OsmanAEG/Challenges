// LeetCode: 977
// Squares of a Sorted Array

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> squares(nums.size(), 0);
    int idx = 0;

    int zero = nums.size() - 1;

    int prev = nums[0]*nums[0];

    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i]*nums[i] > prev) {
        zero = i - 1;
        break;
      }

      prev = nums[i]*nums[i];
    }

    squares[idx] = nums[zero]*nums[zero];
    ++idx;

    int left  = zero - 1;
    int right = zero + 1;

    while(left >= 0 && right < nums.size()) {
      if(nums[left]*nums[left] <= nums[right]*nums[right]) {
        squares[idx] = nums[left]*nums[left];
        --left;
      } else {
        squares[idx] = nums[right]*nums[right];
        ++right;
      }

      ++idx;
    }

    while(left >= 0) {
      squares[idx] = nums[left]*nums[left];
      --left;
      ++idx;
    }

    while(right < nums.size()) {
      squares[idx] = nums[right]*nums[right];
      ++right;
      ++idx;
    }

    return squares;
  }
};