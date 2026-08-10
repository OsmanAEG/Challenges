// Project Euler: 36
// Double-base Palindromes

#include <algorithm>
#include <iostream>
#include <string>

using Int_T = unsigned long long;
using String_T = std::string;

String_T to_binary(Int_T num) {
  String_T binary = "";

  while(num > 0) {
    const auto digit = num%2;
    binary += digit + '0';
    num /= 2;
  }

  std::reverse(binary.begin(), binary.end());

  return binary;
}

bool is_palindrome(String_T s) {
  Int_T low = 0;
  Int_T high = s.size() - 1;

  while(low < high) {
    if(s[low] != s[high]) return false;

    ++low;
    --high;
  }

  return true;
}

int main() {
  Int_T n = 1E6;
  Int_T sum = 0;

  for(Int_T i = 1; i < n; ++i) {
    const auto i_str = std::to_string(i);

    if(is_palindrome(i_str)) {
      const auto i_binary = to_binary(i);

      if(is_palindrome(i_binary)) sum += i;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}