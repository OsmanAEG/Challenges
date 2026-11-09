// LeetCode: 297
// Serialize and Deserialize Binary Tree

#include <sstream>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    std::string result = "";

    if(root == nullptr) {
      result += "#";
      result += ",";
      return result;
    }

    result += std::to_string(root->val);
    result += ",";

    const auto left_result = serialize(root->left);
    const auto right_result = serialize(root->right);

    result += left_result;
    result += right_result;

    return result;
  }

  void dfs_deserialization(TreeNode*& root, const std::vector<std::string>& pre_order_tree, int& idx) {
    if(idx == pre_order_tree.size()) return;

    const auto val = pre_order_tree[idx];
    ++idx;

    if(val == "#") {
      root = nullptr;
      return;
    }

    root = new TreeNode(std::stoi(val));

    dfs_deserialization(root->left, pre_order_tree, idx);
    dfs_deserialization(root->right, pre_order_tree, idx);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    std::vector<std::string> pre_order_tree;
    std::stringstream ss(data);
    std::string val;

    while(std::getline(ss, val, ',')) {
      pre_order_tree.push_back(val);
    }

    TreeNode* root = nullptr;
    int idx = 0;

    dfs_deserialization(root, pre_order_tree, idx);

    return root;
  }
};