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
    vector<vector<int>> levelOrder(TreeNode *root) {

        if (!root)
            return {};

        myQueue.push(root);
        int levelSize;

        vector<vector<int>> finalAns;

        while (!myQueue.empty()) {

            levelSize = myQueue.size();
            vector<int> myVec;

            while (levelSize--) {
                TreeNode *temp = myQueue.front();
                myQueue.pop();

                if (temp->left)
                    myQueue.push(temp->left);
                if (temp->right)
                    myQueue.push(temp->right);

                myVec.push_back(temp->val);
            }

            finalAns.push_back(myVec);
        }

        return finalAns;
    }
};
