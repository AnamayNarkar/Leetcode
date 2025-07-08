#include <bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;

// You are given an array of distinct integers nums and a target integer target.
// Your task is to return a list of all unique combinations of nums where the
// chosen numbers sum to target.
//
// The same number may be chosen from nums an unlimited number of times. Two
// combinations are the same if the frequency of each of the chosen numbers is
// the same, otherwise they are different.
//
// You may return the combinations in any order and the order of the numbers in
// each combination can be in any order.
//
// Example 1:
//
// Input:
// nums = [2,5,6,9]
// target = 9
//
// Output: [[2,2,5],[9]]
//
// Explanation:
// 2 + 2 + 5 = 9. We use 2 twice, and 5 once.
// 9 = 9. We use 9 once.
//
// Example 2:
//
// Input:
// nums = [3,4,5]
// target = 16
//
// Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]
//
// Example 3:
//
// Input:
// nums = [3]
// target = 5
//
// Output: []
//
// Constraints:
//
//     All elements of nums are distinct.
//     1 <= nums.length <= 20
//     2 <= nums[i] <= 30
//     2 <= target <= 30

class Solution {
private:
  void helper(vector<int> &nums, int target, vector<vector<int>> &finalAns,
              vector<int> curr, int itr = 0, int currSum = 0) {

    // base cases
    if (itr > nums.size() - 1 || currSum > target) {
      return;
    }

    if (currSum == target) {
      finalAns.push_back(curr);
      return; // shouldnt be return if the Constraints said that 0 is a valid
              // element of nums
    }

    curr.push_back(nums.at(itr));
    helper(nums, target, finalAns, curr, itr, currSum + nums.at(itr));

    curr.pop_back();
    helper(nums, target, finalAns, curr, itr + 1, currSum);
  }

public:
  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> finalAns;
    helper(nums, target, finalAns, {});
    return finalAns;
  }
};

int main() {
  Solution s;
  vector<vector<int>> vec;
  vector<int> nums = {2, 5, 6, 9};
  int target = 9;
  vec = s.combinationSum(nums, target);
  vector<vector<int>> expected = {{2, 2, 5}, {9}};
  if (vec == expected)
    cout << "lesssgooooooo" << endl;
  else
    cout << "nooooooooooooooooo" << endl;
}
