#include <bits/stdc++.h>
using namespace std;

//=== TLE ===
//   Time Complexity: O(N)
//   Space Complexity: O(N)

class Solution {
  public:
    void check(int &temp, unordered_set<int> &mySet, int digit) {
        while (true) {
            if (mySet.find(digit++) != mySet.end()) {
                temp++;
            } else {
                break;
            }
        }
    }

    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> mySet;
        for (int num : nums) {
            mySet.insert(num);
        }
        int maxSoFar = 0;
        int temp;
        for (int num : nums) {
            temp = 0;
            check(temp, mySet, num);
            maxSoFar = temp > maxSoFar ? temp : maxSoFar;
        }
        return maxSoFar;
    }
};

//=== Better Working version of the above ===

// time complexity: O(n)
// space complexity: O(n)
// differences: 1. reduced the function call overhead by using the while loop directly in the main function
//              2.

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int maxSoFar = 0;
        int temp;
        for (int num : mySet) {
            temp = 0;
            if (mySet.find(num - 1) == mySet.end()) {
                int digit = num;
                while (true) {
                    if (mySet.find(digit++) != mySet.end()) {
                        temp++;
                    } else {
                        break;
                    }
                }
            }
            maxSoFar = temp > maxSoFar ? temp : maxSoFar;
        }
        return maxSoFar;
    }
};

//=== Working ===
// time complexity: O(nlogn + n)
// space complexity: O(1)

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxSoFar = 0;
        int temp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                maxSoFar = temp > maxSoFar ? temp : maxSoFar;
                continue;
            } else if (nums[i - 1] + 1 == nums[i]) {
                temp++;
            } else {
                temp = 1;
            }
            maxSoFar = temp > maxSoFar ? temp : maxSoFar;
        }

        return maxSoFar > temp ? maxSoFar : temp;
    }
};

// === Better ===