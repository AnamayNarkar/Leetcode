#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        for (char c : s) {
            if (myMap.find(c) == myMap.end()) {
                myMap.insert(make_pair(c, 0));
            } else {
                myMap[c]++;
            }
        }

        unordered_map<char, int> myMap2;
        for (char c : t) {
            if (myMap2.find(c) == myMap2.end()) {
                myMap2.insert(make_pair(c, 0));
            } else {
                myMap2[c]++;
            }
        }

        if (myMap2.size() != myMap.size()) {
            return false;
        }

        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            if (myMap2.find(it->first) == myMap2.end() || it->second != myMap2[it->first]) {
                return false;
            }
        }

        return true;
    }
};