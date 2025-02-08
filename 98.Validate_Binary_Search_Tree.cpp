#include <bits/stdc++.h>
using namespace std;

//========== beats 100% =================
// but O(n) space complexity

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
    bool customIsSorted(vector<int> &vec) {
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1]) {
                return false;
            }
        }
        return true;
    }

    void helper(TreeNode *root) {

        if (root == nullptr)
            return;

        helper(root->left);
        inOrder.push_back(root->val);
        helper(root->right);
    }

    bool isValidBST(TreeNode *root) {
        helper(root);
        return customIsSorted(inOrder);
    }
};

//========== beats 100% =================
// better space complexity

class Solution {
  public:
    bool isValidBST(TreeNode *root, long long min = LLONG_MIN, long long max = LLONG_MAX) {

        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};
