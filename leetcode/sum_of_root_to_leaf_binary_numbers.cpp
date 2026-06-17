// LeetCode: 1022
// Sum of Root to Leaf Binary Numbers

#include <string>

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
  int sum = 0;

  void dfs(TreeNode* root, std::string running_sum) {
    if(root == nullptr) return;

    running_sum += std::to_string(root->val);

    if(root->left == nullptr && root->right == nullptr) {
      sum += std::stoi(running_sum, nullptr, 2);
      return;
    }

    dfs(root->left,  running_sum);
    dfs(root->right, running_sum);
  }

  int sumRootToLeaf(TreeNode* root) {
    dfs(root, "");
    return sum;
  }
};