// LeetCode: 50
// Pow(x,n)

class Solution {
public:
  double myPow(long double x, long long n) {
    if(n < 0) {
      x = 1.0 / x;
      n *= -1;
    }

    double result = 1.0;

    while(n > 0) {
      if(n % 2 == 1) result *= x;

      x *= x;
      n /= 2;
    }

    return result;
  }
};