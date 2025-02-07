#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  private:
    int maxi;

  public:
    int heightOfTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int height = 0;
        height = max(heightOfTree(root->left), heightOfTree(root->right));
        return 1 + height;
    }

    void helper(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        maxi = max(heightOfTree(root->left) + heightOfTree(root->right), maxi);
        helper(root->left);
        helper(root->right);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        maxi = 0;
        helper(root);
        return maxi;
    }
};
