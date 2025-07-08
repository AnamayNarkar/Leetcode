#include <iostream>
#include <ratio>
#include <vector>
using namespace std;

// Trapping Rain Water
//
// You are given an array of non-negative integers height which represent an
// elevation map. Each value height[i] represents the height of a bar, which has
// a width of 1.
//
// Return the maximum area of water that can be trapped between the bars.
//
// Example 1:
//
// Input: height = [0,2,0,3,1,0,1,3,2,1]
//
//  Row 2 │    #~~~#
//  Row 1 │  #~#~~~##
//  Row 0 │  #~##~####
//
// Output: 9
//
// Constraints:
//
//     1 <= height.length <= 1000
//     0 <= height[i] <= 1000
//

class Solution { // time O(3n) -> O(n) and space O(n)
public:
  int trap(vector<int> &height) {
    int size = height.size();
    vector<pair<int, int>> map(size); // left max and right max for each col

    int maxSoFar =
        0; // for both left and right are going to be open spaces so both are 0

    for (int i = 0; i < size; ++i) {
      map.at(i).first = maxSoFar;
      maxSoFar = max(maxSoFar, height.at(i));
    }

    maxSoFar = 0;
    for (int i = size - 1; i >= 0; --i) {
      map.at(i).second = maxSoFar;
      maxSoFar = max(maxSoFar, height.at(i));
    }

    int finalAns = 0;
    for (int i = 0; i < size; ++i) {
      finalAns += min(map[i].first, map[i].second) - height[i] >= 0
                      ? min(map[i].first, map[i].second) - height[i]
                      : 0;
    }
    return finalAns;
  }
};

class Solution2 { // constant space, time O(n)
public:
  int trap(vector<int> &height) {
    int leftPtr = 0;
    int rightPtr = height.size() - 1;
    int finalAns = 0;

    int leftMax = height[leftPtr];
    int rightMax = height[rightPtr];

    while (leftPtr < rightPtr) {
      if (height[leftPtr] < height[rightPtr]) {
        leftPtr++;
        leftMax = max(leftMax, height[leftPtr]);
        finalAns += max(0, leftMax - height[leftPtr]);
      } else {
        rightPtr--;
        rightMax = max(rightMax, height[rightPtr]);
        finalAns += max(0, rightMax - height[rightPtr]);
      }
    }
    return finalAns;
  }
};

int main() {
  Solution2 s;
  vector<int> height = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  cout << s.trap(height); // should be 9
}
