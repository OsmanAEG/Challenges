// LeetCode: 509
// Fibonacci Number

class Solution {
public:
  int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int f_nm2 = 0;
    int f_nm1 = 1;

    for(int i = 2; i <= n; ++i) {
      const auto tmp = f_nm1;

      f_nm1 = f_nm1 + f_nm2;
      f_nm2 = tmp;
    }

    return f_nm1;
  }
};