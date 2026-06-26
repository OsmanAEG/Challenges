// Project Euler: 5
// Smallest Multiple

#include <algorithm>
#include <iostream>
#include <string>

template<typename Int_T>
bool is_valid(const Int_T num, const Int_T factors) {
  for(Int_T i = 1; i <= factors; ++i) {
    if(num%i != 0) return false;
  }

  return true;
}

int main() {
  using Int_T = unsigned long long;

  Int_T factors = 20;
  Int_T max = 1;

  for(Int_T i = 1; i <= 20; ++i) max *= i;

  Int_T smallest_multiple = 0;

  for(Int_T i = factors; i <= max; ++i) {
    if(is_valid(i, factors)) {
      smallest_multiple = i;
      break;
    }
  }

  std::cout << smallest_multiple << std::endl;

  return 0;
}