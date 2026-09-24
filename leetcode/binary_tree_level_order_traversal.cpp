// LeetCode: 102
// Binary Tree Level Order Traversal

#include <algorithm>
#include <map>
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
  std::map<int, std::vector<int>> my_map;
  int max_level = 0;

  void search(TreeNode* root, int level) {
    if(root == nullptr) return;

    my_map[level].push_back(root->val);
    max_level = std::max(max_level, level);

    search(root->left, level + 1);
    search(root->right, level + 1);
  }

  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;

    if(root == nullptr) return result;

    search(root, 0);

    for(int i = 0; i <= max_level; ++i) result.push_back(my_map[i]);

    return result;
  }
};