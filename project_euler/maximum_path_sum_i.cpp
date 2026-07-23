// Project Euler: 18
// Maximum Path Sum I

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using Int_T = unsigned long long;
using String_T = std::string;

Int_T max_sum = 0;

std::vector<std::string> get_input() {
  std::ifstream file("maximum_path_sum_i_input.txt");

  std::vector<std::string> nums;
  std::string line;

  while(std::getline(file, line)) {
    if(!line.empty()) nums.push_back(line);
  }

  return nums;
}

template<typename Graph_T>
void path_sum(const Graph_T& graph, Int_T lvl, Int_T idx, Int_T sum) {
  if(lvl >= graph.size()) {
    max_sum = std::max(max_sum, sum);
  } else {
    sum += graph[lvl][idx];
    path_sum(graph, lvl + 1, idx, sum);
    path_sum(graph, lvl + 1, idx + 1, sum);
  }
}

int main() {
  const auto input = get_input();

  std::vector<std::vector<Int_T>> graph;

  for(const auto& row : input) {
    std::vector<Int_T> level;
    String_T num = "";
    for(const auto& c : row) {
      if(c == ' ') {
        level.push_back(std::stoull(num));
        num = "";
      } else {
        num += c;
      }
    }
    level.push_back(std::stoull(num));
    num = "";
    graph.push_back(level);
  }

  path_sum(graph, 0, 0, 0);

  std::cout << max_sum << std::endl;

  return 0;
}