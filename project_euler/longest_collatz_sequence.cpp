// Project Euler: 14
// Longest Collatz Sequence

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<typename Int_T>
Int_T collatz_sequence(Int_T n) {
  Int_T len = 1;

  while(n != 1) {
    if(n%2 == 0) n = n/2;
    else n = 3*n + 1;

    ++len;
  }

  return len;
}

int main() {
  using Int_T = unsigned long long;
  Int_T starting_num = 0;
  Int_T largest_len = 0;

  for(Int_T i = 1; i < 1E6; ++i) {
    const Int_T len_i = collatz_sequence(i);
    if(len_i > largest_len) {
      starting_num = i;
      largest_len = len_i;
    }
  }

  std::cout << starting_num << std::endl;

  return 0;
}