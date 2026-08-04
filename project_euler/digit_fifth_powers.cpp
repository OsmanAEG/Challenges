// Project Euler: 30
// Digit Fifth Powers

#include <iostream>
#include <string>
#include <vector>

using Int_T = unsigned long long;
using String_T = std::string;

Int_T pow(Int_T val, Int_T power) {
  Int_T result = 1;

  for(Int_T i = 0; i < power; ++i) {
    result *= val;
  }

  return result;
}

bool is_digit_power(String_T val, Int_T power) {
  Int_T sum = 0;

  for(const auto& digit : val) {
    const auto result = pow(digit - '0', power);
    sum += result;
  }

  if(std::to_string(sum) == val) return true;
  return false;
}

void find_digit_powers(Int_T& res, String_T val, Int_T power, Int_T len) {
  if(val.size() > len) return;
  if(val.size() == len && is_digit_power(val, power)) res += std::stoull(val);

  if(val.size() == 0) {
    for(int i = 1; i < 10; ++i) find_digit_powers(res, val + static_cast<char>(i + '0'), power, len);
  } else {
    for(int i = 0; i < 10; ++i) find_digit_powers(res, val + static_cast<char>(i + '0'), power, len);
  }
}

int main() {
  Int_T power = 5;
  Int_T res = 0;

  Int_T len = 6;

  for(Int_T i = 2; i <= len; ++i) {
    find_digit_powers(res, "", power, i);
  }

  std::cout << res << std::endl;

  return 0;
}