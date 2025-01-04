#include <bits/stdc++.h>
using namespace std;

// === Working ===
// Beats 16.47%

class Solution {
  public:
    bool isAlphaNumeric(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); }

    string convertToAlphaNumericOnly(string str) {
        string newStr = "";
        for (char c : str) {
            if (isAlphaNumeric(c))
                newStr += c;
        }
        return newStr;
    }

    bool isPalindrome(string s) {
        s = convertToAlphaNumericOnly(s);
        int end = s.length() - 1;
        int start = 0;
        while (start <= end) {
            if (tolower(s[start++]) != tolower(s[end--])) {
                return false;
            }
        }
        return true;
    }
};

// === Better ===
// Beats 100%

class Solution {
  public:
    bool isAlphaNumeric(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'); }

    bool isPalindrome(string s) {
        int end = s.length() - 1;
        int start = 0;
        while (start <= end) {
            if (!isAlphaNumeric(s[start])) {
                start++;
                continue;
            } else if (!isAlphaNumeric(s[end])) {
                end--;
                continue;
            } else {
                if (tolower(s[start++]) != tolower(s[end--])) {
                    return false;
                }
            }
        }
        return true;
    }
};
