// LeetCode: 226
// Invert Binary Tree

//  Definition for a binary tree node.
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
  void dfs_invert(TreeNode* root) {
    if(root != nullptr) {
      const auto left  = root->left;
      const auto right = root->right;

      root->left  = right;
      root->right = left;

      dfs_invert(root->left);
      dfs_invert(root->right);
    }
  }

  TreeNode* invertTree(TreeNode* root) {
    dfs_invert(root);
    return root;
  }
};