// Project Euler: 10
// Summation of Primes

#include <algorithm>
#include <cmath>
#include <iostream>

template<typename Int_T>
bool is_prime(const Int_T num) {
  if(num < 2) return false;

  for(Int_T i = 2; i <= std::sqrt(num); ++i) {
    if(num%i == 0) return false;
  }

  return true;
}

int main() {
  using Int_T = unsigned long long;
  Int_T sum = 0;
  Int_T num = 2E6;

  for(Int_T i = 2; i < num; ++i) {
    if(is_prime(i)) sum += i;
  }

  std::cout << sum << std::endl;

  return 0;
}