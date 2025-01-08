#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<pair<int, int>> stk;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (stk.empty() || temperatures[i] <= stk.top().first) {
                stk.push(make_pair(temperatures[i], i));
            } else {
                while (!stk.empty() && temperatures[i] > stk.top().first) {
                    int num = stk.top().first;
                    int ind = stk.top().second;
                    stk.pop();
                    ans[ind] = i - ind;
                }
                stk.push(make_pair(temperatures[i], i));
            }
        }
        return ans;
    }
};
