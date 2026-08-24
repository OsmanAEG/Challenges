// Project Euler: 48
// Self Powers

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T n = 1000;
  std::string sum = "";

  for(Int_T i = 1; i <= n; ++i) {
    std::cout << i << std::endl;
    std::string sum_i = std::to_string(i);

    for(Int_T j = 1; j < i; ++j) {
      sum_i = multiply_strs(sum_i, i);
    }

    sum = add_strs(sum_i, sum);
  }

  std::cout << sum << std::endl;

  return 0;
}