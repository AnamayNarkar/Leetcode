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
  public:
    int heightOfTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int height = 0;
        height = max(heightOfTree(root->left), heightOfTree(root->right));
        return 1 + height;
    }

    bool isBalanced(TreeNode *root) {

        if (root == nullptr) {
            return true;
        }

        if (abs(heightOfTree(root->left) - heightOfTree(root->right)) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
