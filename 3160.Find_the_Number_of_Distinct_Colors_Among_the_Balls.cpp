#include <bits/stdc++.h>
using namespace std;

// time complexity: O(n)
// beats 79.42%

static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries) {
        vector<int> ans;
        int tempAns = 0;
        unordered_map<int, int> ballAndColor;
        unordered_map<int, int> colorAndCount;
        ans.reserve(queries.size());
        for (vector<int> &ele : queries) {
            if (ballAndColor[ele[0]] != 0) {
                if (--colorAndCount[ballAndColor[ele[0]]] == 0) {
                    tempAns--;
                }
            }
            if (colorAndCount[ele[1]] == 0) {
                tempAns++;
            }
            colorAndCount[ele[1]]++;
            ballAndColor[ele[0]] = ele[1];
            ans.push_back(tempAns);
        }
        return ans;
    }
};