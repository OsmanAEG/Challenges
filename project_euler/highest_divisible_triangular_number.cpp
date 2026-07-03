// Project Euler: 12
// Highly Divisible Triangular Number

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<typename Int_T>
Int_T find_num_divisors(Int_T n) {
  Int_T num = 0;

  for(int i = 1; i*i <= n; ++i) {
    if(n%i == 0) num += 2;
    if(i*i == n) num -= 1;
  }

  return num;
}

int main() {
  using Int_T = unsigned long long;
  using String_T = std::string;

  Int_T div = 500;
  Int_T idx = 1;
  Int_T num = 1;

  bool found_num = false;

  while(!found_num) {
    if(find_num_divisors(num) > div) {
      found_num = true;
      break;
    } else {
      ++idx;
      num += idx;
    }
  }

  std::cout << num << std::endl;

  return 0;
}