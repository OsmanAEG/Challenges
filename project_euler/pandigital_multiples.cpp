// Project Euler: 38
// Pandigital Multiples

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

bool is_pandigital(String_T num) {
  String_T pandigits = "123456789";

  std::sort(num.begin(), num.end());

  if(num == pandigits) return true;

  return false;
}

int main() {
  Int_T num_limit = 10000;
  Int_T result_limit = 9;

  Int_T n = 1;
  Int_T num = 2;

  Int_T max = 0;

  while(num < num_limit) {
    Int_T product = num;
    std::string result = "";

    while(result.size() < result_limit) {
      product = num*n;
      result += std::to_string(product);
      ++n;

      if(result.size() == result_limit && is_pandigital(result)) {
        max = std::max(max, std::stoull(result));
      }
    }

    n = 1;
    ++num;
  }

  std::cout << max << std::endl;

  return 0;
}