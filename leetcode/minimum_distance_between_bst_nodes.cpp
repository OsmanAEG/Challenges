// LeetCode: 783
// Minimum Distance Between BST Nodes

#include <algorithm>
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
  int min = INT_MAX;
  TreeNode* prev = nullptr;

  void dfs(TreeNode* root) {
    if(root == nullptr) return;

    dfs(root->left);

    if(prev != nullptr) min = std::min(root->val - prev->val, min);
    prev = root;

    dfs(root->right);
  }

  int minDiffInBST(TreeNode* root) {
    min = INT_MAX;
    prev = nullptr;

    dfs(root);

    return min;
  }
};