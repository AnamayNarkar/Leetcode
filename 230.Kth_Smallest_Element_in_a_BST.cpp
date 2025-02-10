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
    vector<int> inOrder;

  public:
    void helper(TreeNode *root) {
        if (root == nullptr)
            return;

        helper(root->left);
        inOrder.push_back(root->val);
        helper(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        helper(root);
        return inOrder[k - 1];
    }
};
