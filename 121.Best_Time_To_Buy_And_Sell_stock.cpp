#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                ans = max(ans, prices[right] - prices[left]);
            }
            right++;
        }
        return ans;
    }
};
