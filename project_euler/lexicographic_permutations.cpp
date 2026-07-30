// Project Euler: 24
// Lexicographic Permutations

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

void get_permutations(std::vector<std::string>& permutations,
                      std::string permuation, std::string digits) {
  if(digits.size() == 0) {
    permutations.push_back(permuation);
    return;
  }

  for(int i = 0; i < digits.size(); ++i) {
    auto digit_i = digits[i];
    auto digits_i = digits;
    digits_i.erase(digits_i.begin() + i);
    get_permutations(permutations, permuation + digit_i, digits_i);
  }
}

int main() {
  int n = 1000000;
  std::vector<std::string> permutations;
  std::string digits = "0123456789";

  get_permutations(permutations, "", digits);

  std::sort(permutations.begin(), permutations.end());

  std::cout << permutations[n - 1] << std::endl;

  return 0;
}