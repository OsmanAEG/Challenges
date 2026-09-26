// LeetCode: 230
// Kth Smallest Element in a BST

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
  std::vector<int> tree_values;

  void search(TreeNode* root) {
    if(root == nullptr) return;

    search(root->left);
    tree_values.push_back(root->val);
    search(root->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    search(root);
    return tree_values[k-1];
  }
};