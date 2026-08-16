// Project Euler: 41
// Pandigital Prime

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

int main() {
  Int_T cur_num = 9999999;

  Int_T max_prime = 0;

  while(cur_num > 1) {
    if(is_pandigital(std::to_string(cur_num)) && is_prime(cur_num)) {
      max_prime = cur_num;
      break;
    }

    --cur_num;
  }

  std::cout << max_prime << std::endl;

  return 0;
}