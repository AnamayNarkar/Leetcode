#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<pair<int, int>> prefix;

    bool check(string &square, int num, int index, int strLen, int currSum) {
        if (index == strLen) {
            return currSum == num;
        }

        for (int i = index; i < strLen; ++i) {
            int sum = stoi(square.substr(index, i - index + 1));
            if (check(square, num, i + 1, strLen, currSum + sum))
                return true;
        }
        return false;
    }

  public:
    Solution() : prefix(1001) {
        int sum = 0;
        for (int i = 1; i <= 1000; ++i) {
            prefix[i].first = i * i;
            string temp = to_string(prefix[i].first);
            if (check(temp, i, 0, temp.length(), 0)) {
                sum += prefix[i].first;
                // cout<<i<<" is good sum is"<<sum<<endl;
            }
            prefix[i].second = sum;
        }
    }

    int punishmentNumber(int n) { return prefix[n].second; }
};