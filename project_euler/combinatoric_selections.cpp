// Project Euler: 53
// Combinatoric Selections

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

int main() {
  const Int_T n_min = 1;
  const Int_T n_max = 100;

  const Int_T result_max = 1000000;

  Int_T num = 0;

  for(Int_T n = n_min; n <= n_max; ++n) {
    Int_T r = 0;

    Int_T result = INT_MAX;

    while(r < n) {
      result = combinatoric(n, r);
      if(result > result_max) ++num;

      ++r;
    }
  }

  std::cout << num << std::endl;

  return 0;
}