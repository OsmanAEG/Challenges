// Project Euler: 51
// Prime Digit Replacements

#include "helper.h"

using Int_T = unsigned long long;

void get_digit_combos(std::vector<std::vector<Int_T>>& digits, std::vector<Int_T> group, Int_T n, Int_T idx) {
  digits.push_back(group);

  for(Int_T i = idx; i < n; ++i) {
    auto group_i = group;
    group_i.push_back(i);

    get_digit_combos(digits, group_i, n, i + 1);
  }
}

bool is_prime_digit_replacements(Int_T num, Int_T val) {
  if(!is_prime(num)) return false;

  const auto num_str = std::to_string(num);
  const Int_T n = std::to_string(num).size();

  std::vector<std::vector<Int_T>> digits;

  get_digit_combos(digits, {}, n, 0);

  for(const auto& remove : digits) {
    if(remove.empty()) continue;

    std::vector<std::string> num_str_combos;

    auto tmp_num_str = num_str;

    bool valid_check = true;
    auto check = tmp_num_str[remove[0]];

    for(const auto& idx : remove) {
      if(check != tmp_num_str[idx]) {
        valid_check = false;
      }
    }

    if(!valid_check) continue;

    for(Int_T i = 0; i < 10; ++i) {
      for(const auto& idx : remove) {
        tmp_num_str[idx] = i + '0';
      }

      if(tmp_num_str[0] != '0' && is_prime(std::stoull(tmp_num_str))){
        num_str_combos.push_back(tmp_num_str);
      }
    }

    if(num_str_combos.size() == val) return true;

    num_str_combos.clear();
  }

  return false;
}

int main() {
  Int_T num = 2;
  Int_T val = 8;

  bool found = false;

  while(!found) {
    found = is_prime_digit_replacements(num, val);

    if(found) break;
    else ++num;
  }

  std::cout << num << std::endl;

  return 0;
}