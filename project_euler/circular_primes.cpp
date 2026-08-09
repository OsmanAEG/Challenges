// Project Euler: 35
// Circular Primes

#include <cmath>
#include <iostream>

using Int_T = unsigned long long;
using String_T = std::string;

template<typename Int_T>
bool is_prime(const Int_T num) {
  if(num < 2) return false;

  for(Int_T i = 2; i <= std::sqrt(num); ++i) {
    if(num%i == 0) return false;
  }

  return true;
}

void check_circular_primes(bool& circular_prime, String_T num_str) {
  for(Int_T i = 0; i < num_str.size(); ++i) {
    circular_prime = is_prime(std::stoull(num_str));

    if(circular_prime == false) return;

    num_str = num_str.substr(1) + num_str[0];
  }
}

int main() {
  const Int_T min = 2;
  const Int_T max = 1E6;

  Int_T num_primes = 0;

  for(Int_T i = min; i < max; ++i) {
    if(is_prime(i)) {
      const String_T i_str = std::to_string(i);
      bool circular_prime = true;

      check_circular_primes(circular_prime, i_str);

      if(circular_prime == true) ++num_primes;
    }
  }

  std::cout << num_primes << std::endl;
}