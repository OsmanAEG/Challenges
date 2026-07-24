// Project Euler: 20
// Factorial Digit Sum

#include <iostream>
#include <string>

using Int_T = unsigned long long;
using String_T = std::string;

String_T multiply_strs(String_T num, Int_T multiple) {
  String_T result = num;
  const Int_T n = num.size();

  for(Int_T m = 0; m < multiple - 1; ++m) {

    bool extra = false;

    for(int i = n - 1; i >= 0; --i) {
      const int adj = result.size() - n + i;
      int sum = (result[adj] - '0') + (num[i] - '0');

      if(extra == true) sum += 1;

      if(sum >= 10) {
        result[adj] = (sum - 10) + '0';
        extra = true;
      } else {
        result[adj] = sum + '0';
        extra = false;
      }
    }

    if(result.size() > num.size()) {
      int i = result.size() - num.size() - 1;

      while(i >= 0 && extra == true) {
        int sum = (result[i] - '0') + 1;

        if(sum >= 10) {
          result[i] = (sum - 10) + '0';
          extra = true;
        } else {
          result[i] = sum + '0';
          extra = false;
        }

        --i;
      }
    }

    if(extra == true) result = "1" + result;
  }

  return result;
}

int main() {
  const Int_T n = 100;
  String_T result = "1";

  for(int i = 1; i <= n; ++i) {
    result = multiply_strs(result, i);
  }

  Int_T sum_factorial = 0;

  for(Int_T i = 0; i < result.size(); ++i) {
    sum_factorial += (result[i] - '0');
  }

  std::cout << sum_factorial << std::endl;
}