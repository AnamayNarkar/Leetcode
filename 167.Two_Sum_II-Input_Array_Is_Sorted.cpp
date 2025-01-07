#include <bits/stdc++.h>
using namespace std;

//=== Working ===
// Beats 3%

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans(2, -1);
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++) {
            if (map.find(target - numbers[i]) == map.end()) {
                map.insert(make_pair(numbers[i], i));
            } else {
                ans[0] = map[target - numbers[i]] + 1;
                ans[1] = i + 1;
                return ans;
            }
        }
        return ans;
    }
};

//=== Better Two Pointer ===
// constance space
// Beats 100%

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans(2, -1);
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] > target) {
                end--;
            } else if (numbers[start] + numbers[end] < target) {
                start++;
            } else {
                ans[0] = start + 1;
                ans[1] = end + 1;
                return ans;
            }
        }
        return ans;
    }
};