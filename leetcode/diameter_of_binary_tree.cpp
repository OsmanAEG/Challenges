// LeetCode: 543
// Diameter of Binary Tree

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
  int max_length = 0;

  int dfs(TreeNode* root) {
    if(root == nullptr) return 0;

    auto left  = dfs(root->left);
    auto right = dfs(root->right);

    max_length = std::max(max_length, left + right);

    return 1 + std::max(left, right);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return max_length;
  }
};