// LeetCode: 6
// Zigzag Conversion

#include <string>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    std::vector<std::vector<char>> graph;
    int idx = 0;

    while(idx < s.size()) {
      std::vector<char> row(numRows, '-');

      for(int i = 0; i < numRows; ++i) {
        row[i] = s[idx];
        ++idx;

        if(idx >= s.size()) break;
      }

      graph.push_back(row);

      for(int j = numRows - 2; j >= 1; --j) {
        if(idx >= s.size()) break;
        std::vector<char> diag(numRows, '-');
        diag[j] = s[idx];
        ++idx;
        graph.push_back(diag);
      }
    }

    std::string result = "";

    for(int j = 0; j < graph[0].size(); ++j) {
      for(int i = 0; i < graph.size(); ++i) {
        if(graph[i][j] != '-') result += graph[i][j];
      }
    }

    return result;
  }
};