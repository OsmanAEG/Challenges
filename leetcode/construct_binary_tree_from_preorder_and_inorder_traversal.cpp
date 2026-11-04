// LeetCode: 105
// Construct Binary Tree from Preorder and Inorder Traversal

#include <unordered_map>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  using Map_T = std::unordered_map<int, int>;

  TreeNode* constructTree(std::vector<int>& preorder, int& pre_idx, int left, int right, const Map_T& in_map) {
    if(left > right) return nullptr;

    int root_val = preorder[pre_idx];
    ++pre_idx;

    TreeNode* root = new TreeNode(root_val);

    int in_idx = in_map.at(root_val);

    root->left  = constructTree(preorder, pre_idx, left, in_idx - 1, in_map);
    root->right = constructTree(preorder, pre_idx, in_idx + 1, right, in_map);

    return root;
  }

  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    Map_T in_map;

    for(int i = 0; i < inorder.size(); ++i) in_map[inorder[i]] = i;

    int pre_idx = 0;

    return constructTree(preorder, pre_idx, 0, inorder.size() - 1, in_map);
  }
};