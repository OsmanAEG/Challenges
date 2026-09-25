// LeetCode: 637
// Average of Levels in Binary Tree

#include <algorithm>
#include <map>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::map<int, std::vector<int>> my_map;
  int max_level = 0;

  void search(TreeNode* root, int level) {
    if(root == nullptr) return;

    my_map[level].push_back(root->val);
    max_level = std::max(max_level, level);

    search(root->left, level + 1);
    search(root->right, level + 1);
  }

  std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> result;

    if(root == nullptr) return result;

    search(root, 0);

    for(int i = 0; i <= max_level; ++i) {
      double average = 0.0;

      for(int j = 0; j < my_map[i].size(); ++j) {
        average += static_cast<double>(my_map[i][j]);
      }

      average /= static_cast<double>(my_map[i].size());

      result.push_back(average);
    }

    return result;
  }
};