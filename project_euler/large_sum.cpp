// Project Euler: 13
// Large Sum

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> get_input() {
  std::ifstream file("large_sum_input.txt");

  std::vector<std::string> nums;
  std::string line;

  while(std::getline(file, line)) {
    if(!line.empty()) nums.push_back(line);
  }

  return nums;
}

int main() {
  const int n = 50;

  const auto input = get_input();
  std::string result = "";
  for(int i = 0; i < n; ++i) result += '0';

  for(const auto& num : input) {
    bool extra = false;

    for(int i = n - 1; i >= 0; --i) {
      const int adj = result.size() - n + i;
      int sum = (result[adj] - '0') + (num[i] - '0');

      if(extra == true) sum += 1;

      if(sum >= 10) {
        result[adj] = (sum - 10) + '0';
        extra = true;
      } else {
        result[adj] = sum + '0';
        extra = false;
      }
    }

    const int m = result.size() - n;

    for(int i = m - 1; i >= 0; --i) {
      int sum = (result[i] - '0');

      if(extra == true) sum += 1;

      if(sum >= 10) {
        result[i] = (sum - 10) + '0';
        extra = true;
      } else {
        result[i] = sum + '0';
        extra = false;
      }
    }

    if(extra == true) result = "1" + result;
    extra = false;
  }

  std::cout << "result" << std::endl;
  std::cout << result << std::endl;
  std::cout << "first ten" << std::endl;

  for(int i = 0; i < 10; ++i) { std::cout << result[i]; }

  std::cout << std::endl;

  return 0;
}