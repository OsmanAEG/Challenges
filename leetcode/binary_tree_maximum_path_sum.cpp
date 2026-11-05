// Binary Tree Maximum Path Sum

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
  int max_sum = INT_MIN;

  int find_max_path_sum(TreeNode* root) {
    if(root == nullptr) return 0;

    const auto left_sum  = std::max(0, find_max_path_sum(root->left));
    const auto right_sum = std::max(0, find_max_path_sum(root->right));

    max_sum = std::max(max_sum, root->val + left_sum + right_sum);

    return root->val + std::max(left_sum, right_sum);
  }

  int maxPathSum(TreeNode* root) {
    find_max_path_sum(root);
    return max_sum;
  }
};