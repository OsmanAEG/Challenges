// LeetCode: 1448
// Count Good Nodes in Binary Tree

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
  int good_nodes = 0;

  void count_good_nodes(TreeNode* root, int running_max) {
    if(root == nullptr) return;

    if(root->val >= running_max) {
      ++good_nodes;
      running_max = root->val;
    }

    count_good_nodes(root->left,  running_max);
    count_good_nodes(root->right, running_max);
  }

  int goodNodes(TreeNode* root) {
    count_good_nodes(root, INT_MIN);
    return good_nodes;
  }
};