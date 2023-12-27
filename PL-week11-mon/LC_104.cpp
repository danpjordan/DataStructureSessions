// Solution to LeetCode Question 104 - Maximum Depth of Binary Tree

#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);
    return max(depthLeft, depthRight) + 1;
  }
};