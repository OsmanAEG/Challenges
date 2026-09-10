// Project Euler: 62
// Cubic Permutations

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  const Int_T N = 5;
  bool has_N = false;

  Int_T root = 1;
  Int_T num = root*root*root;

  std::size_t num_digits = 1;

  std::map<std::string, std::vector<Int_T>> cube_groups;

  while(!has_N) {
    auto num_str = std::to_string(num);

    if(num_str.size() != num_digits) {
      for(const auto& [key, cubes] : cube_groups) {
        if(cubes.size() == N) {
          num = std::min(num, cubes.front());
          has_N = true;
        }
      }

      if(has_N) break;

      cube_groups.clear();
      num_digits = num_str.size();

    }

    std::sort(num_str.begin(), num_str.end());

    cube_groups[num_str].push_back(num);

    ++root;
    num = root*root*root;

  }

  std::cout << num << std::endl;

  return 0;
}