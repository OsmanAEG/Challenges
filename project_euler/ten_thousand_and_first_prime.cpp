// Project Euler: 7
// 10 001st Prime

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

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

  Int_T prime_num = 2;
  Int_T max_it = 10001;

  int it = 1;

  while(it < max_it) {
    ++prime_num;

    while(!is_prime(prime_num)) ++prime_num;

    ++it;
  }

  std::cout << prime_num << std::endl;

  return 0;
}