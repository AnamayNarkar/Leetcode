#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {

        unordered_map<int, int> myMap;

        for (int i : nums) {
            myMap[i]++;
        }

        vector<pair<int, int>> pairVec;

        for (auto i : myMap) {
            pairVec.push_back({i.second, i.first});
        }

        sort(pairVec.rbegin(), pairVec.rend());

        vector<int> ans;
        int pairVecPtr = 0;

        while (k--) {
            ans.push_back(pairVec[pairVecPtr++].second);
        }

        return ans;
    }
};
