#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums[0];
        int mid;
        while (left <= right) {

            mid = left + (right - left) / 2;

            if (nums[left] < nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            ans = min(ans, nums[mid]);

            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
