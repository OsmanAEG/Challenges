// LeetCode: 100
// Same Tree

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
  bool same = true;

  void check_same(TreeNode* p, TreeNode* q) {
    if(same == false) return;

    if(p == nullptr && q != nullptr) same = false;
    if(p != nullptr && q == nullptr) same = false;

    if(p != nullptr && q != nullptr) {
      if(p->val != q->val) same = false;

      isSameTree(p->left, q->left);
      isSameTree(p->right, q->right);
    }
  }

  bool isSameTree(TreeNode* p, TreeNode* q) {
    check_same(p, q);
    return same;
  }
};