// Project Euler: 55
// Lychrel Numbers

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

int main() {
  const Int_T n = 10000;
  const Int_T step_limit = 50;

  Int_T num_lychrel = 0;

  for(Int_T i = 1; i < n; ++i) {
    Int_T step = 1;

    auto num = lychrel_step(i);

    while(step <= step_limit) {
      if(is_palindrome_number(num)) break;
      num = lychrel_step(num);

      ++step;
    }

    if(step > 50) ++num_lychrel;
  }

  std::cout << num_lychrel << std::endl;

  return 0;
}