#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<vector<int>> &nums) {
        map<int, int> myMap;
        bool first = true;
        for (vector<int> &num : nums) {
            for (int &i : num) {
                myMap[i]++;
            }
        }
        vector<int> finalAns;
        int req = nums.size();
        for (pair<const int, int> &p : myMap) {
            if (p.second == req) {
                finalAns.push_back(p.first);
            }
        }
        return finalAns;
    }
};