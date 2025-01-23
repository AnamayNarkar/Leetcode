#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool compare(unordered_map<char, int> &smallStrMap, unordered_map<char, int> &bigStrMap) {

        for (auto it = smallStrMap.begin(); it != smallStrMap.end(); it++) {

            if (bigStrMap[it->first] < it->second) {
                return false;
            }
        }

        return true;
    }

    string helper(string &bigStr, string &smallStr) {

        if (smallStr.length() > bigStr.length()) {
            return "";
        }

        unordered_map<char, int> smallStrMap;

        for (char c : smallStr) {
            smallStrMap[c]++;
        }

        int right = 0, left = 0;

        int startIndex = 0;
        int minLength = INT_MAX;

        unordered_map<char, int> bigStrMap;

        while (right < bigStr.length()) {

            bigStrMap[bigStr[right]]++;

            if (compare(smallStrMap, bigStrMap)) {

                while (compare(smallStrMap, bigStrMap)) {
                    if (right - left + 1 < minLength) {
                        minLength = right - left + 1;
                        startIndex = left;
                    }
                    bigStrMap[bigStr[left]]--;
                    left++;
                }
            }
            right++;
        }

        return minLength == INT_MAX ? "" : bigStr.substr(startIndex, minLength);
    }

    string minWindow(string s, string t) { return helper(s, t); }
};
