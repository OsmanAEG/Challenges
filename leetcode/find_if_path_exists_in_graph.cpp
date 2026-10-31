// LeetCode: 1971
// Find if Path Exists in Graph

#include <vector>

#include <queue>
#include <vector>

class Solution {
public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    std::vector<std::vector<int>> adjacent_nodes(n);

    for(const auto& edge : edges) {
      adjacent_nodes[edge[0]].push_back(edge[1]);
      adjacent_nodes[edge[1]].push_back(edge[0]);
    }

    std::queue<int> node_queue;
    std::vector<bool> visited_nodes(n, false);

    node_queue.push(source);
    visited_nodes[source] = true;

    while(!node_queue.empty()) {
      int node = node_queue.front();
      node_queue.pop();

      if(node == destination) return true;

      for(const auto& neighbor : adjacent_nodes[node]) {
        if(!visited_nodes[neighbor]) {
          visited_nodes[neighbor] = true;
          node_queue.push(neighbor);
        }
      }
    }

    return false;
  }
};