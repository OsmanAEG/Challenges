// LeetCode: 278
// First Bad Version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    unsigned long long low = 1;
    unsigned long long high = n;

    while(low < high) {
      unsigned long long mid = (low + high)/2;

      if(isBadVersion(mid) == true) high = mid;
      else low = mid + 1;
    }

    return low;
  }
};