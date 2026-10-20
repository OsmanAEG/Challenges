// LeetCode: 62
// Unique Paths

#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> ways(m, std::vector<int>(n, 0));

    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == 0 && j == 0) ways[i][j] = 1;
        else if(i == 0 && j > 0) ways[i][j] = ways[i][j-1];
        else if(i > 0 && j == 0) ways[i][j] = ways[i-1][j];
        else ways[i][j] = ways[i-1][j] + ways[i][j-1];
      }
    }

    return ways[m-1][n-1];
  }
};