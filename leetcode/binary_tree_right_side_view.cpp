// LeetCode: 199
// Binary Tree Right Side View

#include <set>
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
  std::vector<int> right_vals;
  std::set<int> covered_levels;

  void right_most_val_finder(TreeNode* root, int level_counter) {
    if(root == nullptr) return;

    if(covered_levels.find(level_counter) == covered_levels.end()) {
      right_vals.push_back(root->val);
      covered_levels.insert(level_counter);
    }

    right_most_val_finder(root->right, level_counter + 1);
    right_most_val_finder(root->left, level_counter + 1);
  }

  std::vector<int> rightSideView(TreeNode* root) {
    right_most_val_finder(root, 0);
    return right_vals;
  }
};