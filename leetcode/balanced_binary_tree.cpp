// LeetCode: 110
// Balanced Binary Tree

#include <algorithm>

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
  int tree_height(TreeNode* root) {
    if(root == nullptr) return 0;

    const auto height_left = tree_height(root->left);
    const auto height_right = tree_height(root->right);

    return std::max(height_left, height_right) + 1;
  }

  bool check_balanced(TreeNode* root) {
    if(root == nullptr) return true;

    const auto left_size = tree_height(root->left);
    const auto right_size = tree_height(root->right);

    if(std::abs(left_size - right_size) > 1) return false;

    return check_balanced(root->left) && check_balanced(root->right);
  }

  bool isBalanced(TreeNode* root) {
    return check_balanced(root);
  }
};