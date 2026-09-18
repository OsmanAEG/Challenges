// Project Euler: 74
// Digit Factorial Chains

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

int main() {
  const Int_T N = 1000000;
  const Int_T target = 60;

  Int_T num_target = 0;

  for(Int_T i = 1; i < N; ++i) {
    std::unordered_set<Int_T> set_i;
    Int_T num_i = i;

    Int_T loop_size = 0;

    while(set_i.find(num_i) == set_i.end()) {
      ++loop_size;

      set_i.insert(num_i);
      const auto num_i_str = num_i.str();

      Int_T sum_i = 0;

      for(const auto c : num_i_str) {
        sum_i += factorial(c - '0');
      }

      num_i = sum_i;
    }

    if(loop_size == target) ++num_target;
  }

  std::cout << num_target << std::endl;

  return 0;
}