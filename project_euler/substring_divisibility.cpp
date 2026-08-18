// Project Euler: 43
// Substring Divisibility

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;
using Vector_T = std::vector<std::string>;

bool is_divisible(String_T num_str) {
  std::vector<Int_T> divs = {2, 3, 5, 7, 11, 13, 17};

  for(Int_T i = 1; i < 8; ++i) {
    String_T d_i_str = "";

    d_i_str += num_str[i];
    d_i_str += num_str[i+1];
    d_i_str += num_str[i+2];

    const Int_T num = std::stoull(d_i_str);

    if(num%divs[i-1] != 0) return false;
  }

  return true;
}

void get_combos(std::vector<String_T>& nums, const std::vector<char> options, String_T num) {
  if(num.size() == 10) {
    if(num[0] != '0') nums.push_back(num);
    return;
  }

  for(Int_T i = 0; i < options.size(); ++i) {
    auto options_i = options;
    options_i.erase(options_i.begin() + i);
    get_combos(nums, options_i, num + options[i]);
  }
}

int main() {
  Int_T sum = 0;

  const std::vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::vector<String_T> nums;

  get_combos(nums, digits, "");

  for(const auto& num : nums) {
    if(is_divisible(num)) sum += std::stoull(num);
  }

  std::cout << sum << std::endl;

  return 0;
}