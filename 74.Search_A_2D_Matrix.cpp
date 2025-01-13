#include <bits/stdc++.h>
using namespace std;

// === Binary Search PerRow ===
// Time Complexity: O(nlogm)

class Solution {
  public:
    int searchPerRow(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (searchPerRow(matrix[i], target) != -1)
                return true;
        }
        return false;
    }
};

// === Better ===
// Time Complexity: O(log(m*n))
// first find which row to search using binary search
// then search the target in that row using binary search

class Solution {
  public:
    int searchRow(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int whichRowToSearch(vector<vector<int>> &matrix, int target) {

        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int top = 0;
        int bottom = rows;
        int mid;

        while (top <= bottom) {

            mid = top + (bottom - top) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][cols]) {
                return mid;
            } else if (target > matrix[mid][cols]) {
                top = mid + 1;
            } else if (target < matrix[mid][0]) {
                bottom = mid - 1;
            }
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int rowToSearch = whichRowToSearch(matrix, target);
        if (rowToSearch == -1) {
            return false;
        } else {
            int ans = searchRow(matrix[rowToSearch], target);
            if (ans == -1) {
                return false;
            } else {
                return true;
            }
        }
    }
};