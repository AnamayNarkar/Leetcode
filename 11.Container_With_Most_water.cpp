#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &heights) {
        int length = heights.size();
        int maxHeightSoFar = 0;
        int start = 0;
        int end = length - 1;
        while (start < end) {
            maxHeightSoFar = max(maxHeightSoFar, min(heights[start], heights[end]) * (end - start));
            if (heights[start] > heights[end]) {
                end--;
            } else {
                start++;
            }
        }
        return maxHeightSoFar;
    }
};
