// LeetCode: 104
// Maximum Depth of Binary Tree

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
  int max_depth = 0;

  void find_max_depth(TreeNode* root, int depth) {
    if(root == nullptr) {
      max_depth = std::max(max_depth, depth);
    } else {
      find_max_depth(root->left,  depth + 1);
      find_max_depth(root->right, depth + 1);
    }
  }

  int maxDepth(TreeNode* root) {
    find_max_depth(root, 0);
    return max_depth;
  }
};