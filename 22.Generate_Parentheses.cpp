#include <bits/stdc++.h>
using namespace std;

// === my badass recursive solution ===
//  beats 5.65%

class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && ((c == ']' && st.top() == '[') || (c == ')' && st.top() == '(') || (c == '}' && st.top() == '{'))) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }

    int countOpen(string str) { return count(str.begin(), str.end(), '('); }

    int countClose(string str) { return count(str.begin(), str.end(), ')'); }

    void helper(vector<string> &vec, string str, int n) {
        if (str.length() == n * 2) {
            if (isValid(str)) {
                vec.push_back(str);
            }
            return;
        }

        if (countOpen(str) < n) {
            helper(vec, str + "(", n);
        }

        if (countClose(str) < n) {
            helper(vec, str + ")", n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "(", n);
        return ans;
    }
};

// === Better O(n) solution ===

class Solution {
  public:
    void helper(int openC, int closeC, int n, vector<string> &vec, string str) {
        if (openC == closeC && openC == n) {
            vec.push_back(str);
            return;
        }

        if (openC < n) {
            helper(openC + 1, closeC, n, vec, str + "(");
        }

        if (closeC < openC) {
            helper(openC, closeC + 1, n, vec, str + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        helper(0, 0, n, ans, str);
        return ans;
    }
};
