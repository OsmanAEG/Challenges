// Project Euler: 40
// Champernowne's Constant

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

int main() {
  Int_T n = 1;
  Int_T n_target = 1;
  Int_T n_max = 1000000;

  Int_T num = 1;
  Int_T product = 1;

  while(n <= n_max) {
    const String_T num_str = std::to_string(num);

    if(n + num_str.size() > n_target) {
      Int_T idx = n_target - n;
      product *= num_str[idx] - '0';

      n_target *= 10;
    }

    n += num_str.size();
    ++num;
  }

  std::cout << product << std::endl;
}