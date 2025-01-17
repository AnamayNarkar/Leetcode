#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int maxElement = *std::max_element(piles.begin(), piles.end());
        int leftPtr = 1, rightPtr = maxElement;
        int mid;
        int ans = rightPtr;
        long long totalTime;
        while (leftPtr <= rightPtr) {
            totalTime = 0;
            mid = leftPtr + (rightPtr - leftPtr) / 2;
            for (auto singlePile : piles) {
                totalTime += ceil((double)singlePile / mid);
            }

            if (totalTime <= h) {
                ans = mid;
                rightPtr = mid - 1;
            } else {
                leftPtr = mid + 1;
            }
        }
        return ans;
    }
};
