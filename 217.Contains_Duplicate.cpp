#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {

        unordered_map<int, int> myMap;
        for (int i : nums) {
            if (myMap.find(i) == myMap.end()) {
                myMap.insert(make_pair(i, 0));
            } else {
                return true;
            }
        }
        return false;
    }
};