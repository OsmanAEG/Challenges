// LeetCode: 367
// Valid Perfect Square

class Solution {
public:
  bool isPerfectSquare(int num) {
    if(num == 1) return true;

    unsigned long long low = 1;
    unsigned long long high = num/2;

    while(low <= high) {
      unsigned long long mid = (low + high)/2;

      if(mid*mid > num) high = mid - 1;
      else if(mid*mid < num) low = mid + 1;
      else return true;
    }

    return false;
  }
};