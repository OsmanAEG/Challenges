// Project Euler: 81
// Path Sum Two Ways

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  const auto filename = "path_sum_two_ways_input.txt";
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

  const Int_T N = map.size();

  std::vector<std::vector<Int_T>> sums(N, std::vector<Int_T>(N, 0));

  sums[0][0] = map[0][0];

  for(Int_T i = 1; i < N; ++i) {
    sums[i][0] = sums[i - 1][0] + map[i][0];
  }

  for(Int_T j = 1; j < N; ++j) {
    sums[0][j] = sums[0][j - 1] + map[0][j];
  }

  for(Int_T i = 1; i < N; ++i) {
    for(Int_T j = 1; j < N; ++j) {
      sums[i][j] = map[i][j] + std::min(sums[i - 1][j], sums[i][j - 1]);
    }
  }

  std::cout << sums[N - 1][N - 1] << std::endl;

  return 0;
}