// LeetCode: 112
// Path Sum

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
  bool has_target_sum = false;
  int target;

  void find_target_sum(TreeNode* root, int sum) {
    if(root == nullptr || has_target_sum) return;

    sum += root->val;

    if(root->left == nullptr && root->right == nullptr) {
      if(sum == target) has_target_sum = true;
      return;
    }

    find_target_sum(root->left, sum);
    find_target_sum(root->right, sum);
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    target = targetSum;
    find_target_sum(root, 0);
    return has_target_sum;
  }
};