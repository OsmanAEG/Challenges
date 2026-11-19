// LeetCode: 73
// Set Matrix Zeroes

#include <set>
#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::set<int> rows;
    std::set<int> cols;

    for(int i = 0; i < matrix.size(); ++i) {
      for(int j = 0; j < matrix[0].size(); ++j) {
        if(matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for(const auto& row : rows) {
      for(int i = 0; i < matrix[0].size(); ++i) {
        matrix[row][i] = 0;
      }
    }

    for(const auto& col : cols) {
      for(int i = 0; i < matrix.size(); ++i) {
        matrix[i][col] = 0;
      }
    }
  }
};