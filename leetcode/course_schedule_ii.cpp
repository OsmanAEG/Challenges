// LeetCode: 210
// Course Schedule II

#include <vector>

class Solution {
public:
  using Graph_T  = std::vector<std::vector<int>>;
  using Vector_T = std::vector<int>;

  bool has_cycle(int course, const Graph_T& graph, Vector_T& visited, Vector_T& order) {
    if(visited[course] == 1) return true;
    if(visited[course] == 2) return false;

    visited[course] = 1;

    for(const int prerequisite : graph[course]) {
      if(has_cycle(prerequisite, graph, visited, order)) {
        return true;
      }
    }

    visited[course] = 2;

    order.push_back(course);

    return false;
  }

  std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph_T graph(numCourses);
    Vector_T visited(numCourses, 0);
    Vector_T order;

    for(const auto& prerequisite : prerequisites) {
      graph[prerequisite[0]].push_back(prerequisite[1]);
    }

    for(int course = 0; course < numCourses; ++course) {
      if(has_cycle(course, graph, visited, order)) {
        return {};
      }
    }

    return order;
  }
};