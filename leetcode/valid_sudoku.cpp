// LeetCode: 36
// Valid Sudoku

#include<set>
#include<vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    const int m = 9;
    const int n = 9;
    const int b = 3;

    bool valid_sudoku = true;

    std::set<int> nums;

    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        const auto& num = board[i][j];

        if(nums.find(num) != nums.end()) return false;
        if(num != '.') nums.insert(num);
      }

      nums.clear();
    }

    for(int j = 0; j < n; ++j) {
      for(int i = 0; i < m; ++i) {
        const auto& num = board[i][j];

        if(nums.find(num) != nums.end()) return false;
        if(num != '.') nums.insert(num);
      }

      nums.clear();
    }

    for(int b_i = 0; b_i < m; b_i += 3) {
      for(int b_j = 0; b_j < n; b_j += 3) {
        for(int i = 0; i < b; ++i) {
          for(int j = 0; j < b; ++j) {
            const auto& num = board[i + b_i][j + b_j];

            if(nums.find(num) != nums.end()) return false;
            if(num != '.') nums.insert(num);
          }
        }

        nums.clear();
      }
    }

    return true;
  }
};