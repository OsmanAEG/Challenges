// LeetCode: 200
// Number of Islands

#include <queue>
#include <utility>
#include <vector>

using Int_T = int;
using Node_T = std::pair<int, int>;
using Vector_T = std::vector<Int_T>;

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    if(grid.empty()) return 0;

    const Int_T m = grid.size();
    const Int_T n = grid[0].size();

    int islands = 0;

    const Vector_T dx= {-1, 1, 0, 0};
    const Vector_T dy= {0, 0, -1, 1};

    std::queue<Node_T> node_queue;

    for(int row = 0; row < m; ++row) {
      for(int col = 0; col < n; ++col) {
        if(grid[row][col] != '1') continue;

        ++islands;

        node_queue.push({row, col});
        grid[row][col] = '0';

        while(!node_queue.empty()) {
          auto [r, c] = node_queue.front();
          node_queue.pop();

          for(int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) {
              continue;
            }

            if(grid[nr][nc] != '1') continue;

            grid[nr][nc] = '0';
            node_queue.push({nr, nc});
          }
        }
      }
    }

    return islands;
  }
};
