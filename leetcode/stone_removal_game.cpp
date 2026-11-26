// LeetCode: 3360
// Stone Removal Game

class Solution {
public:
  bool canAliceWin(int n) {
    bool is_alice = true;

    int minus_n = 10;

    while(n - minus_n >= 0) {
      is_alice = !is_alice;

      n -= minus_n;
      --minus_n;
    }

    return !is_alice;
  }
};