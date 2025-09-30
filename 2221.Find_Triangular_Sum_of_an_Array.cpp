#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int triangularSum(vector<int> &nums) {
    int mainSize = nums.size();
    int itr = mainSize;
    for (int i = 0; i < mainSize; ++i) {
      for (int j = 0; j < itr - 1; ++j) {
        nums[j] = (nums[j] + nums[j + 1]) % 10;
      }
      itr--;
    }
    return nums[0];
  }
};
