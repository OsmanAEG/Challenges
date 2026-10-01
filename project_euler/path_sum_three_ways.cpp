// Project Euler: 82
// Path Sum Three Ways

#include "helper.h"

using Int_T = unsigned long long;

Int_T find_min_path_sum(const std::vector<std::vector<Int_T>>& map) {
  const Int_T N = map.size();
  std::vector<Int_T> sums(N);

  for(Int_T i = 0; i < N; ++i) sums[i] = map[i][0];

  for(Int_T j = 1; j < N; ++j) {
    for(Int_T i = 0; i < N; ++i) {
      sums[i] += map[i][j];
    }

    for(Int_T i = 1; i < N; ++i) {
      sums[i] = std::min(sums[i], sums[i - 1] + map[i][j]);
    }

    for(Int_T i = N - 1; i > 0; --i) {
      sums[i - 1] = std::min(sums[i - 1], sums[i] + map[i - 1][j]);
    }
  }

  return *std::min_element(sums.begin(), sums.end());
}

int main() {
  const auto filename = "path_sum_three_ways_input.txt";
  const auto input = get_input(filename);

  std::vector<std::vector<Int_T>> map;

  for(const auto& line : input) {
    std::vector<Int_T> row;
    std::string num_str = "";

    for(const auto& c : line) {
      if(c == ',') {
        row.push_back(std::stoull(num_str));
        num_str = "";
      } else {
        num_str += c;
      }
    }

    row.push_back(std::stoull(num_str));
    map.push_back(row);
  }

  const auto result = find_min_path_sum(map);

  std::cout << result << std::endl;

  return 0;
}