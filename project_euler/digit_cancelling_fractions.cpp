// Project Euler: 33
// Digit Cancelling Fractions

#include <iostream>
#include <numeric>
#include <set>
#include <string>

using Int_T = unsigned long long;
using String_T = std::string;

int main() {
  const Int_T min = 10;
  const Int_T max = 100;

  Int_T result_num = 1;
  Int_T result_den = 1;

  for(Int_T num = min; num < max; ++num) {
    for(Int_T den = num + 1; den < max; ++den) {
      String_T num_str = std::to_string(num);
      String_T den_str = std::to_string(den);

      std::set<char> common_digits;

      for(Int_T i = 0; i < num_str.size(); ++i) {
        for(Int_T j = 0; j < den_str.size(); ++j) {
          if(num_str[i] == den_str[j]) common_digits.insert(num_str[i]);
        }
      }

      if(common_digits.size() != 1) continue;
      if(common_digits.find('0') != common_digits.end()) continue;

      for(int i = 0; i < num_str.size(); ++i) {
        if(common_digits.find(num_str[i]) != common_digits.end()) {
          num_str.erase(num_str.begin() + i);
        }
      }

      for(int i = 0; i < den_str.size(); ++i) {
        if(common_digits.find(den_str[i]) != common_digits.end()) {
          den_str.erase(den_str.begin() + i);
        }
      }

      auto num_star = std::stoull(num_str);
      auto den_star = std::stoull(den_str);

      if(den_star == 0) continue;

      if(num * den_star == den * num_star) {
        result_num *= num_star;
        result_den *= den_star;
      }
    }
  }

  const Int_T divisor = std::gcd(result_num, result_den);

  const auto result = result_den / divisor;

  std::cout << result << std::endl;

  return 0;
}