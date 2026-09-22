// LeetCode: 101
// Symmetric Tree

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
  bool is_equal(TreeNode* node1, TreeNode* node2) {
    if(node1 == nullptr && node2 != nullptr) return false;
    if(node2 == nullptr && node1 != nullptr) return false;

    if(node1 == nullptr && node2 == nullptr) return true;

    if(node1->val != node2->val) return false;

    return true;
  }

  bool check_symmetric(TreeNode* node1, TreeNode* node2) {
    if(!is_equal(node1, node2)) return false;

    if(node1 == nullptr && node2 == nullptr) return true;

    return check_symmetric(node1->left, node2->right) && check_symmetric(node1->right, node2->left);
  }

  bool isSymmetric(TreeNode* root) {
    return check_symmetric(root, root);
  }
};