#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int skipIndex(vector<int> &vec, int idx) {
    int num = vec[idx];
    while (idx + 1 < vec.size() && vec[idx] == vec[idx + 1]) {
      idx++;
    }
    return ++idx;
  }

  void helper(vector<int> &nums, vector<vector<int>> &finalAns, int idx,
              vector<int> curr) {

    // base case
    if (idx >= nums.size()) {
      finalAns.push_back(curr);
      return;
    }

    // take
    curr.push_back(nums[idx]);
    helper(nums, finalAns, idx + 1, curr);
    curr.pop_back();

    // dont take
    helper(nums, finalAns, skipIndex(nums, idx), curr);
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> finalAns;
    sort(nums.begin(), nums.end());
    helper(nums, finalAns, 0, {});
    return finalAns;
  }
};
