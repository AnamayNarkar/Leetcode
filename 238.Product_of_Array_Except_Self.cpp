#include <bits/stdc++.h>
using namespace std;

// === With Division Operator ===

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int numberOfZeroes = 0;
        int size = nums.size();
        int product = 1;
        for (int n : nums) {
            if (n == 0)
                numberOfZeroes++;
            else
                product *= n;
        }
        vector<int> ans(size, 0);

        if (numberOfZeroes > 1)
            return ans;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                ans[i] = product;
            } else {
                if (numberOfZeroes == 1) {
                    ans[i] == 0;
                } else {
                    ans[i] = product / nums[i];
                }
            }
        }
        return ans;
    }
};

// === Without Division Operator ===
// prefix product and suffix product method

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int size = nums.size();
        vector<int> ans(size);
        vector<int> prefix(size, 1);
        vector<int> suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
