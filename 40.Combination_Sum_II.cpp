#include <bits/stdc++.h>
using namespace std;

// Combination Sum II
//
//
// You are given an array of integers candidates, which may contain duplicates,
// and a target integer target. Your task is to return a list of all unique
// combinations of candidates where the chosen numbers sum to target.
//
// Each element from candidates may be chosen at most once within a combination.
// The solution set must not contain duplicate combinations.
//
// You may return the combinations in any order and the order of the numbers in
// each combination can be in any order.
//
// Example 1:
//
// Input: candidates = [9,2,2,4,6,1,5], target = 8
//
// Output: [
//   [1,2,5],
//   [2,2,4],
//   [2,6]
// ]
//
// Example 2:
//
// Input: candidates = [1,2,3,4,5], target = 7
//
// Output: [
//   [1,2,4],
//   [2,5],
//   [3,4]
// ]
//
// Constraints:
//
//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30
//
class Solution {
public:
  int sum(vector<int> &vec) {
    int sum = 0;
    for (int it : vec) {
      sum += it;
    }
    return sum;
  }

  int skipIndex(vector<int> &nums, int index) {
    while (nums[index] == nums[index + 1]) {
      index++;
    }
    return ++index;
  }

  void helper(vector<int> &nums, int index, int target, vector<int> curr,
              vector<vector<int>> &finalAns) {

    if (sum(curr) == target) {
      finalAns.push_back(curr);
      return;
    }
    if (index == nums.size() || sum(curr) > target)
      return;

    curr.push_back(nums[index]);
    // cant resue teh same element , so if you take it go up
    helper(nums, index + 1, target, curr, finalAns);
    curr.pop_back();

    // dont take and go up
    helper(nums, skipIndex(nums, index), target, curr, finalAns);
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> finalAns;
    sort(candidates.begin(), candidates.end());
    helper(candidates, 0, target, {}, finalAns);
    return finalAns;
  }
};
