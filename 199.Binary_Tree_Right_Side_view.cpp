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
    queue<TreeNode *> myQueue;

  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root)
            return {};

        myQueue.push(root);
        int levelSize;

        vector<int> finalAns;

        while (!myQueue.empty()) {

            levelSize = myQueue.size();

            while (levelSize--) {
                TreeNode *temp = myQueue.front();
                myQueue.pop();

                if (temp->left)
                    myQueue.push(temp->left);
                if (temp->right)
                    myQueue.push(temp->right);

                if (levelSize == 0)
                    finalAns.push_back(temp->val);
            }
        }

        return finalAns;
    }
};
