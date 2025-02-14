#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkLastPartCharacters(string &stk, int partSize, string &part) {
        int stkPtr = stk.length() - 1;
        while (partSize--) {
            if (part[partSize] != stk[stkPtr]) {
                return false;
            }
            stkPtr--;
        }
        return true;
    }

    void removeLastPartCharacters(string &stk, int partSize) {
        while (partSize--) {
            stk.pop_back();
        }
    }

    string removeOccurrences(string s, string part) {
        string stk;
        int ptr = 0;
        int bigSize = s.length(), smallSize = part.length();
        while (ptr < bigSize) {
            stk += s[ptr];
            while (true) {
                if (stk.length() >= smallSize && checkLastPartCharacters(stk, smallSize, part)) {
                    removeLastPartCharacters(stk, smallSize);
                    // ptr-=smallSize;
                } else {
                    break;
                }
            }
            ptr++;
        }
        return stk;
    }
};