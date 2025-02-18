#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfDigits(int num) {
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int findMax(vector<int> &vec) {

        if (vec.size() < 2) {
            return -1;
        } else {
            sort(vec.begin(), vec.end());
            return vec[vec.size() - 1] + vec[vec.size() - 2];
        }
    }

    int maximumSum(vector<int> &nums) {
        map<int, vector<int>> myMap;
        for (int i = 0; i < nums.size(); i++) {
            myMap[sumOfDigits(nums[i])].push_back(nums[i]);
        }
        int ans = -1;
        for (auto p : myMap) {
            ans = max(ans, findMax(p.second));
        }
        return ans;
    }
};

//======= better==========
class Solution {
  public:
    int sumOfDigits(int num) {
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int findMax(const vector<int> &vec) {
        if (vec.size() < 2)
            return -1;

        int first = INT_MIN, second = INT_MIN;
        for (int num : vec) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second) {
                second = num;
            }
        }
        return first + second;
    }

    int maximumSum(vector<int> &nums) {
        vector<vector<int>> myMap(82);
        for (int i = 0; i < nums.size(); ++i) {
            myMap[sumOfDigits(nums[i])].push_back(nums[i]);
        }
        int ans = -1;
        for (auto p : myMap) {
            ans = max(ans, findMax(p));
        }
        return ans;
    }
};