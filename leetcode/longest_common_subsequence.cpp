// LeetCode: 1143
// Longest Common Subsequence

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    const auto n = text1.size();
    const auto m = text2.size();

    std::vector<std::vector<int>> lens(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        if(text1[i-1] == text2[j-1]) lens[i][j] = lens[i-1][j-1] + 1;
        else lens[i][j] = std::max(lens[i-1][j], lens[i][j-1]);
      }
    }

    return lens[n][m];
  }
};