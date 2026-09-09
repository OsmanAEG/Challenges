// LeetCode: 74
// Search a 2D Matrix

#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int n_low = 0;
    int n_high = matrix.size() - 1;
    int n = -1;

    while(n_low <= n_high) {
      int mid = (n_low + n_high) / 2;

      if(matrix[mid][0] > target) {
        n_high = mid - 1;
      } else {
        n = mid;
        n_low = mid + 1;
      }
    }

    if(n == -1) return false;

    int m_low = 0;
    int m_high = matrix[n].size() - 1;

    while(m_low <= m_high) {
      int mid = (m_low + m_high) / 2;

      if(matrix[n][mid] > target) {
        m_high = mid - 1;
      } else if(matrix[n][mid] < target) {
        m_low = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }
};