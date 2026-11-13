// LeetCode: 994
// Rotting Oranges

#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::pair<int, int>> get_rotten_idx(std::vector<std::vector<int>>& grid) {
    std::vector<std::pair<int, int>> rotten_idx;

    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        if(grid[i][j] == 2) rotten_idx.push_back({i, j});
      }
    }

    return rotten_idx;
  }

  bool has_fresh(std::vector<std::vector<int>>& grid) {
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        if(grid[i][j] == 1) return true;
      }
    }

    return false;
  }

  int orangesRotting(std::vector<std::vector<int>>& grid) {
    auto rotten_idx = get_rotten_idx(grid);
    int counter = 0;

    std::vector<std::pair<int, int>> diff = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while(rotten_idx.size() > 0) {
      std::vector<std::pair<int, int>> rotten_idx_new;

      for(const auto& idx : rotten_idx) {
        for(int i = 0; i < 4; ++i) {
          const int pos_x = idx.first + diff[i].first;
          const int pos_y = idx.second + diff[i].second;

          if(pos_x < 0 || pos_x >= grid.size() || pos_y < 0 || pos_y >= grid[0].size()) {
            continue;
          }

          if(grid[pos_x][pos_y] == 1) {
            grid[pos_x][pos_y] = 2;
            rotten_idx_new.push_back({pos_x, pos_y});
          }
        }
      }

      if(rotten_idx_new.empty()) break;

      ++counter;
      rotten_idx = rotten_idx_new;
    }

    if(has_fresh(grid)) return -1;

    return counter;
  }
};
