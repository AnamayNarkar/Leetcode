#include <bits/stdc++.h>
using namespace std;

//=========== beats 16% ===========

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
    int ans;

  public:
    void helper(TreeNode *root, int maxSoFar) {
        if (root == nullptr) {
            return;
        }
        if (root->val >= maxSoFar) {
            ans++;
        }
        maxSoFar = max(maxSoFar, root->val);
        helper(root->left, maxSoFar);
        helper(root->right, maxSoFar);
    }

    int goodNodes(TreeNode *root) {
        ans = 0;
        int maxSoFar = INT_MIN;
        helper(root, maxSoFar);
        return ans;
    }
};

// ========= optimized beats 98% =========

static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    int goodNodes(TreeNode *root, int maxSoFar = INT_MIN) {
        if (!root)
            return 0;
        int count = root->val >= maxSoFar ? 1 : 0;
        maxSoFar = max(maxSoFar, root->val);
        return count + goodNodes(root->left, maxSoFar) + goodNodes(root->right, maxSoFar);
    }
};
