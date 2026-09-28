// LeetCode: 530
// Minimum Absolute Difference in BST

#include <algorithm>
#include <climits>
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
  std::vector<unsigned long long> vals;

  void search(TreeNode* node) {
    if(node == nullptr) return;

    vals.push_back(node->val);

    search(node->left);
    search(node->right);
  }

  int getMinimumDifference(TreeNode* root) {
    search(root);

    std::sort(vals.begin(), vals.end());

    unsigned long long min_diff = INT_MAX;

    for(unsigned long long i = 0; i < vals.size() - 1; ++i) {
      const auto diff = vals[i + 1] - vals[i];
      min_diff = std::min(diff, min_diff);
    }

    return min_diff;
  }
};