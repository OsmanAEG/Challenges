// LeetCode: 695
// Max Area of Island

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using Int_T = int;
using Node_T = std::pair<int, int>;
using Vector_T = std::vector<Int_T>;

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    if(grid.empty()) return 0;

    const Int_T m = grid.size();
    const Int_T n = grid[0].size();

    const Vector_T dx= {-1, 1, 0, 0};
    const Vector_T dy= {0, 0, -1, 1};

    int islands = 0;
    int island_size = 0;
    int max_island_size = 0;

    std::queue<Node_T> node_queue;

    for(int row = 0; row < m; ++row) {
      for(int col = 0; col < n; ++col) {
        if(grid[row][col] != 1) continue;

        ++islands;
        ++island_size;

        node_queue.push({row, col});
        grid[row][col] = 0;

        while(!node_queue.empty()) {
          auto [r, c] = node_queue.front();
          node_queue.pop();

          for(int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) {
              continue;
            }

            if(grid[nr][nc] != 1) continue;
            ++island_size;

            grid[nr][nc] = 0;
            node_queue.push({nr, nc});
          }
        }

        max_island_size = std::max(max_island_size, island_size);
        island_size = 0;
      }
    }

    return max_island_size;
  }
};