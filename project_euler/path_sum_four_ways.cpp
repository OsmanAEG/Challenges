// Project Euler: 83
// Path Sum Four Ways

#include "helper.h"

using Int_T = long long;

Int_T dijkstra(const std::vector<std::vector<Int_T>>& map) {
  const Int_T N = map.size();
  std::vector<std::vector<Int_T>> sums(N, std::vector<Int_T>(N, LONG_MAX));

  using Node = std::tuple<Int_T, Int_T, Int_T>;
  std::priority_queue<Node, std::vector<Node>,std::greater<Node>> queue;

  sums[0][0] = map[0][0];
  queue.push({sums[0][0], 0, 0});

  const Int_T di[] = {-1, 1, 0, 0};
  const Int_T dj[] = {0, 0, -1, 1};

  while(!queue.empty()) {
    const auto [sum, i, j] = queue.top();
    queue.pop();

    if(sum > sums[i][j]) continue;

    if(i == N - 1 && j == N - 1) return sum;

    for(Int_T k = 0; k < 4; ++k) {
      const Int_T next_i = i + di[k];
      const Int_T next_j = j + dj[k];

      if(next_i < 0 || next_i >= N || next_j < 0 || next_j >= N) continue;

      const Int_T ni = next_i;
      const Int_T nj = next_j;

      const Int_T new_sum = sum + map[ni][nj];

      if(new_sum < sums[ni][nj]) {
        sums[ni][nj] = new_sum;
        queue.push({new_sum, ni, nj});
      }
    }
  }

  return sums[N - 1][N - 1];
}

int main() {
  const auto filename = "path_sum_four_ways_input.txt";
  const auto input = get_input(filename);

  std::vector<std::vector<Int_T>> map;

  for(const auto& line : input) {
    std::vector<Int_T> row;
    std::string num_str = "";

    for(const auto& c : line) {
      if(c == ',') {
        row.push_back(std::stoll(num_str));
        num_str = "";
      } else {
        num_str += c;
      }
    }

    row.push_back(std::stoll(num_str));
    map.push_back(row);
  }

  const Int_T min_sum = dijkstra(map);

  std::cout << min_sum << std::endl;

  return 0;
}