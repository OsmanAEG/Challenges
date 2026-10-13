// LeetCode: 79
// Word Search

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<bool>> visited;
  bool found_word = false;

  void find_word(const std::vector<std::vector<char>>& board, const std::string& target_word, std::string curr_word, int m, int n) {
    if(found_word) return;

    if(m < 0 || m >= board.size()) return;
    if(n < 0 || n >= board[0].size()) return;

    if(visited[m][n]) return;

    if(board[m][n] != target_word[curr_word.size()]) return;

    visited[m][n] = true;
    curr_word += board[m][n];

    if(curr_word.size() == target_word.size()) {
      found_word = true;
      visited[m][n] = false;
      return;
    }

    find_word(board, target_word, curr_word, m + 1, n);
    find_word(board, target_word, curr_word, m - 1, n);
    find_word(board, target_word, curr_word, m, n + 1);
    find_word(board, target_word, curr_word, m, n - 1);

    visited[m][n] = false;
  }

  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    found_word = false;

    if(word.empty()) return true;
    if(board.empty() || board[0].empty()) return false;

    std::vector<std::vector<bool>> visited_init(board.size(), std::vector<bool>(board[0].size(), false));
    visited = visited_init;

    for(int m = 0; m < board.size(); ++m) {
      for(int n = 0; n < board[0].size(); ++n) {
        find_word(board, word, "", m, n);

        if(found_word) return true;
      }
    }

    return false;
  }
};
