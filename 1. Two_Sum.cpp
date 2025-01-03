class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans(2, -1);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
};

// === Better ===

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans(2, -1);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) == map.end()) {
                map.insert(make_pair(nums[i], i));
            } else {
                ans[0] = map[target - nums[i]];
                ans[1] = i;
                return ans;
            }
        }
        return ans;
    }
};