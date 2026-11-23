// LeetCode: 1026
// Maximum Difference Between Node and Ancestor

#include <algorithm>
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
  int max_diff = 0;

  void find_max_diff(TreeNode* root, std::vector<int> candidates) {
    if(root == nullptr) return;

    for(const auto& candidate : candidates) {
      const auto diff = std::abs(root->val - candidate);
      max_diff = std::max(max_diff, diff);
    }

    candidates.push_back(root->val);

    find_max_diff(root->left, candidates);
    find_max_diff(root->right, candidates);
  }

  int maxAncestorDiff(TreeNode* root) {
    find_max_diff(root, {});
    return max_diff;
  }
};