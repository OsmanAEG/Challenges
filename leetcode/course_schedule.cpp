// LeetCode: 207
// Course Schedule

#include <vector>

class Solution {
public:
  using Graph_T  = std::vector<std::vector<int>>;
  using Vector_T = std::vector<int>;

  bool has_cycle(int course, const Graph_T& graph, Vector_T& visited) {
    if(visited[course] == 1) return true;
    if(visited[course] == 2) return false;

    visited[course] = 1;

    for(const int prerequisite : graph[course]) {
      if(has_cycle(prerequisite, graph, visited)) {
        return true;
      }
    }

    visited[course] = 2;

    return false;
  }

  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph_T graph(numCourses);
    Vector_T visited(numCourses, 0);

    for(const auto& prerequisite : prerequisites) {
      graph[prerequisite[0]].push_back(prerequisite[1]);
    }

    for(int course = 0; course < numCourses; ++course) {
      if(has_cycle(course, graph, visited)) {
        return false;
      }
    }

    return true;
  }
};