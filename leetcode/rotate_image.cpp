// LeetCode: 48
// Rotate Image

#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    const auto n = matrix.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        result[j][n - i - 1] = matrix[i][j];
      }
    }

    matrix = result;
  }
};