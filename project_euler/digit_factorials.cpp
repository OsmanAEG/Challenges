// Project Euler: 34
// Digit Factorials

#include <iostream>
#include <string>

using Int_T    = unsigned long long;
using String_T = std::string;

Int_T factorial(Int_T n) {
  Int_T result = 1;

  for(int i = 1; i <= n; ++i) {
    result *= i;
  }

  return result;
}

int main() {
  Int_T sum = 0;
  Int_T num = 10;
  Int_T max = 1E7;

  while(num < max) {
    Int_T factorial_sum = 0;
    const auto num_str = std::to_string(num);

    for(const auto& c : num_str) {
      factorial_sum += factorial(c - '0');
    }

    if(factorial_sum == num) sum += num;
    ++num;
  }

  std::cout << sum << std::endl;

  return 0;
}