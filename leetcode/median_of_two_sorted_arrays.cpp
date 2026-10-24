// LeetCode: 4
// Median of Two Sorted Arrays

#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums;

    while(!nums1.empty() || !nums2.empty()) {
      if(!nums1.empty() && !nums2.empty()) {
        if(nums1[0] < nums2[0]) {
          nums.push_back(nums1[0]);
          nums1.erase(nums1.begin());
        } else {
          nums.push_back(nums2[0]);
          nums2.erase(nums2.begin());
        }
      } else if(!nums1.empty() && nums2.empty()) {
        nums.push_back(nums1[0]);
        nums1.erase(nums1.begin());
      } else {
        nums.push_back(nums2[0]);
        nums2.erase(nums2.begin());
      }
    }

    const auto n = nums.size();

    if(n%2 == 0) {
      return static_cast<double>(nums[n/2] +  nums[n/2-1])/2.0;
    } else {
      return static_cast<double>(nums[n/2]);
    }
  }
};