#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int tupleSameProduct(vector<int> &nums) {

        unordered_map<int, int> productAndCount;
        unordered_map<int, int> productAndNumberOfTuples;

        int length = nums.size();

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                productAndNumberOfTuples[nums[i] * nums[j]] += productAndCount[nums[i] * nums[j]];
                productAndCount[nums[i] * nums[j]]++;
            }
        }

        int res = 0;

        for (auto p : productAndNumberOfTuples) {
            res += p.second * 8;
        }

        return res;
    }
};