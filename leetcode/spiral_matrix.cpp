// LeetCode: 54
// Spiral Matrix

#include <vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result = {};

    if(matrix.empty() || matrix[0].empty()) return result;

    const auto m = matrix[0].size();
    const auto n = matrix.size();

    std::vector<std::vector<bool>> path(matrix.size(), std::vector<bool>(matrix[0].size()));
    result.resize(m*n);

    int x = 0;
    int y = 0;

    int step_x = 1;
    int step_y = 1;

    int idx = 0;

    path[y][x] = true;
    result[idx] = matrix[y][x];
    idx += 1;

    while(idx < m*n) {
      // horizontal stride
      while(x + step_x < m && x + step_x >= 0 && path[y][x+step_x] == false) {
        x += step_x;

        path[y][x] = true;
        result[idx] = matrix[y][x];

        idx += 1;
      }

      step_x *= -1;

      // vertical stride
      while(y + step_y < n && y + step_y >= 0 && path[y+step_y][x] == false) {
        y += step_y;

        path[y][x] = true;
        result[idx] = matrix[y][x];

        idx += 1;
      }

      step_y *= -1;
    }

    return result;
  }
};