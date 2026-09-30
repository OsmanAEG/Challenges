// LeetCode: 235
// Lowest Common Ancestor of a Binary Search Tree

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* lowest;

  void search(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return;

    if(root->val >= p->val && root->val <= q->val) lowest = root;

    if(root->val < p->val) search(root->right, p, q);
    if(root->val > q->val) search(root->left, p, q);
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val > q->val) search(root, q, p);
    else search(root, p, q);

    return lowest;
  }
};
