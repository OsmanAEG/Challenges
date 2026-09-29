// LeetCode: 98
// Validate Binary Search Tree

#include <climits>

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
  bool is_valid = true;

  void search(TreeNode* root, long long max, long long min) {
    if(root == nullptr) return;

    if(root->val >= max) is_valid = false;
    if(root->val <= min) is_valid = false;

    if(is_valid == false) return;

    search(root->left, root->val, min);
    search(root->right, max, root->val);
  }

  bool isValidBST(TreeNode* root) {
    search(root, LLONG_MAX, LLONG_MIN);
    return is_valid;
  }
};