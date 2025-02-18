#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long countBadPairs(vector<int> &nums) {
        long long goodPairs = 0;
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            goodPairs += myMap[i - nums[i]];
            myMap[i - nums[i]]++;
        }
        return (nums.size() * (nums.size() - 1) / 2) - goodPairs;
    }
};