// Project Euler: 3
// Largest Prime Factor

#include <algorithm>
#include <cmath>
#include <iostream>

template<typename Int_T>
bool is_prime(const Int_T num) {
  if(num < 2) return false;

  for(Int_T i = 2; i < std::sqrt(num); ++i) {
    if(num%i == 0) return false;
  }

  return true;
}

int main() {
  using Int_T = unsigned long long;
  Int_T largest = 1;
  Int_T num = 600851475143;

  for(Int_T i = 2; i < std::sqrt(num); ++i) {
    if(num%i == 0 && is_prime(i)) largest = i;
  }

  std::cout << largest << std::endl;

  return 0;
}