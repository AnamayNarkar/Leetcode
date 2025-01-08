#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int length = position.size();
        stack<float> stk;
        vector<pair<int, int>> vec(length);
        for (int i = 0; i < length; i++) {
            vec[i] = {position[i], speed[i]};
        }

        sort(vec.begin(), vec.end());

        for (int i = 0; i < length; i++) {
            stk.push((float)(target - vec[i].first) / vec[i].second);
        }

        int fleetCount = length;
        float temp;
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            while (!stk.empty() && stk.top() <= temp) {
                stk.pop();
                fleetCount--;
            }
        }

        return fleetCount;
    }
};
