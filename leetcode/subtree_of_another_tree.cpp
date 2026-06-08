// LeetCode: 572
// Subtree of Another Tree

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
  bool found_same = false;

  void check_same(TreeNode* root, TreeNode* subRoot, bool& same) {
    if(same == false) return;
    if(root == nullptr && subRoot == nullptr) return;

    if(root == nullptr && subRoot != nullptr) {
      same = false;
      return;
    }

    if(root != nullptr && subRoot == nullptr) {
      same = false;
      return;
    }

    if(root->val != subRoot->val) {
      same = false;
      return;
    } else {
      check_same(root->left,  subRoot->left,  same);
      check_same(root->right, subRoot->right, same);
    }
  }

  void dfs(TreeNode* root, TreeNode* subRoot) {
    if(found_same == true || root == nullptr) return;

    bool same = true;
    check_same(root, subRoot, same);
    if(same == true) {
      found_same = true;
      return;
    }

    dfs(root->left,  subRoot);
    dfs(root->right, subRoot);
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    dfs(root, subRoot);
    return found_same;
  }
};