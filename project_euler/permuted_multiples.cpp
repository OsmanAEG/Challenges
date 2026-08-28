// Project Euler: 52
// Permuted Multiples

#include "helper.h"

using Int_T = unsigned long long;

bool is_permuted_multiples(Int_T num) {
  auto num_str = std::to_string(num);
  std::sort(num_str.begin(), num_str.end());

  for(Int_T i = 1; i <= 6; ++i) {
    const auto num_i = i*num;
    auto num_i_str = std::to_string(num_i);
    std::sort(num_i_str.begin(), num_i_str.end());
    if(num_i_str != num_str) return false;
  }

  return true;
}

int main() {
  Int_T num = 1;
  bool found = false;

  while(!found) {
    if(is_permuted_multiples(num)) {
      found = true;
      break;
    }

    ++num;
  }

  std::cout << num << std::endl;

  return 0;
}