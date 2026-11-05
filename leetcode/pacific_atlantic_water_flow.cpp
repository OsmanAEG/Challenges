// LeetCode: 417
// Pacific Atlantic Water Flow

#include <vector>

#include <vector>
#include <algorithm>

class Solution {
public:
  int n_rows;
  int n_cols;

  void dfs(int row, int col, const std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& visited) {
    visited[row][col] = true;

    const int d_row[4] = {1, -1, 0, 0};
    const int d_col[4] = {0, 0, 1, -1};

    for(int i = 0; i < 4; i++) {
      const auto new_row = row + d_row[i];
      const auto new_col = col + d_col[i];

      if(new_row < 0 || new_row >= n_rows || new_col < 0 || new_col >= n_cols) continue;

      if(visited[new_row][new_col]) continue;

      if(heights[new_row][new_col] < heights[row][col]) continue;

      dfs(new_row, new_col, heights, visited);
    }
  }

  std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
    n_rows = heights.size();
    n_cols = heights[0].size();

    std::vector<std::vector<bool>> pacific(n_rows, std::vector<bool>(n_cols, false));
    std::vector<std::vector<bool>> atlantic(n_rows, std::vector<bool>(n_cols, false));

    for(int col = 0; col < n_cols; col++) {
      dfs(0, col, heights, pacific);
      dfs(n_rows - 1, col, heights, atlantic);
    }

    for(int row = 0; row < n_rows; row++) {
      dfs(row, 0, heights, pacific);
      dfs(row, n_cols - 1, heights, atlantic);
    }

    std::vector<std::vector<int>> result;

    for(int row = 0; row < n_rows; row++) {
      for(int col = 0; col < n_cols; col++) {
        if(pacific[row][col] && atlantic[row][col]) {
          result.push_back({row, col});
        }
      }
    }

    return result;
  }
};