#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        unordered_map<char, int> myMap;
        int ans = 1;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (myMap.find(s[right]) == myMap.end()) {
                ans = max(ans, right - left + 1);
                myMap[s[right]] = right;
            } else {

                if (myMap[s[right]] < left) {
                    myMap[s[right]] = right;
                    ans = max(ans, right - left + 1);
                    right++;
                    continue;
                }

                left = myMap[s[right]] + 1;
                ans = max(ans, right - left + 1);
                myMap[s[right]] = right;
            }
            right++;
        }
        return ans;
    }
};
