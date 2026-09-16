// Project Euler: 68
// Magic 5-gon Ring

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

std::vector<std::vector<String_T>> get_num_str_permutations(std::vector<String_T> num_strs) {
  std::vector<std::vector<String_T>> result;
  std::sort(num_strs.begin(), num_strs.end());
  result.push_back(num_strs);

  while(std::next_permutation(num_strs.begin(), num_strs.end())) result.push_back(num_strs);

  return result;
}

int main() {
  const Int_T N = 16;

  Int_T result = 0;

  std::vector<String_T> num_options = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

  std::vector<std::vector<Int_T>> line_options = {{0, 1, 2}, {3, 2, 4}, {5, 4, 6}, {7, 6, 8}, {9, 8, 1}};

  const auto permutations = get_num_str_permutations(num_options);

  for(const auto& permutation : permutations) {
    const Int_T required_sum = std::stoull(permutation[0]) + std::stoull(permutation[1]) + std::stoull(permutation[2]);
    bool is_magic = true;

    for(const auto& line : line_options) {
      Int_T line_sum = 0;

      for(const auto node : line) line_sum += std::stoull(permutation[node]);

      if(line_sum != required_sum) {
        is_magic = false;
        break;
      }
    }

    if(!is_magic) continue;

    const Int_T first_outer = std::stoull(permutation[0]);

    if(first_outer > std::stoull(permutation[3]) ||
       first_outer > std::stoull(permutation[5]) ||
       first_outer > std::stoull(permutation[7]) ||
       first_outer > std::stoull(permutation[9])) {
       continue;
    }

    std::string result_p;

    for(const auto& line : line_options) {
      for(const auto node : line) result_p += permutation[node];
    }

    if(result_p.size() == N) result = std::max(result, std::stoull(result_p));
  }

  std::cout << result << '\n';

  return 0;
}