// Project Euler: 4
// Largest Palindrome Product

#include <algorithm>
#include <iostream>
#include <string>

template<typename String_T>
bool is_palindrome(const String_T x) {
  int low = 0;
  int high = x.size() - 1;

  while(low <= high) {
    if(x[low] != x[high]) return false;
    ++low;
    --high;
  }

  return true;
}

int main() {
  using Int_T = unsigned long long;

  Int_T largest_palindrome = 0;

  for(Int_T i = 0; i <= 999; ++i) {
    for(Int_T j = 0; j <= 999; ++j) {
      const auto num = i*j;

      if(is_palindrome(std::to_string(num))) {
        largest_palindrome = std::max(largest_palindrome, num);
      }
    }
  }

  std::cout << largest_palindrome << std::endl;

  return 0;
}