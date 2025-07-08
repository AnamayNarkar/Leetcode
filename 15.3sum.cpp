#include <bits/stdc++.h>
using namespace std;

//=== Working ===
// Beats 7%

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        set<vector<int>> mySet;

        sort(nums.begin(), nums.end());

        int length = nums.size();
        int start;
        int end = length - 1;

        vector<vector<int>> ans;

        for (int i = 0; i < length; i++) {
            start = i + 1;
            end = length - 1;
            while (start < end) {
                if (nums[start] + nums[end] + nums[i] > 0) {
                    end--;
                } else if (nums[start] + nums[end] + nums[i] < 0) {
                    start++;
                } else {
                    if (!mySet.count({nums[i], nums[start], nums[end]})) {
                        ans.push_back({nums[i], nums[start], nums[end]});
                        mySet.insert({nums[i], nums[start], nums[end]});
                    }
                    start++;
                    end--;
                }
            }
        }
        return ans;
    }
};

// beats 70%

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> finalAns;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int begin = i + 1;
            int end = nums.size() - 1;

            while (begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if (sum < 0) {
                    ++begin;
                } else if (sum > 0) {
                    --end;
                } else {
                    finalAns.push_back({nums[i], nums[begin], nums[end]});
                    ++begin;
                    --end;
                    while (begin < end && nums[begin] == nums[begin - 1]) ++begin;
                    while (begin < end && nums[end] == nums[end + 1]) --end;
                }
            }
        }

        return finalAns;
    }
};
