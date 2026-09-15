// Project Euler: 67
// Maximum Path Sum II

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

Int_T max_sum = 0;

template<typename Graph_T>
Int_T path_sum(Graph_T& graph) {
  for(Int_T lvl = graph.size() - 1; lvl > 0; --lvl) {
    for(Int_T idx = 0; idx < graph[lvl - 1].size(); ++idx) {
      graph[lvl - 1][idx] += std::max(graph[lvl][idx], graph[lvl][idx + 1]);
    }
  }

  return graph[0][0];
}

int main() {
  const auto filename = "maximum_path_sum_ii_input.txt";
  const auto input = get_input(filename);

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

  const auto result = path_sum(graph);

  std::cout << result << std::endl;

  return 0;
}