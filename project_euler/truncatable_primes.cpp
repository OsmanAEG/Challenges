// Project Euler: 37
// Truncatable Primes

#include "helper.h"

using Int_T = unsigned long long;

bool is_truncatable_prime(Int_T num) {
  std::unordered_set<Int_T> truncations;

  std::string num_str = std::to_string(num);
  std::string left = "";
  std::string right = "";

  for(Int_T i = 0; i < num_str.size(); ++i) {
    Int_T low = i;
    Int_T high = num_str.size() - 1 - i;

    left = left + num_str[low];
    right = num_str[high] + right;

    truncations.insert(std::stoull(left));
    truncations.insert(std::stoull(right));
  }

  for(const auto& truncation : truncations) {
    if(!is_prime(truncation)) return false;
  }

  return true;
}

int main() {
  Int_T sum = 0;
  Int_T counter = 0;

  Int_T idx = 10;

  while(counter < 11) {
    if(is_truncatable_prime(idx)) {
      sum += idx;
      ++counter;
    }

    ++idx;
  }

  std::cout << sum << std::endl;

  return 0;
}