#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<string> stk;
        string c1, c2;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                if (s == "+") {
                    c1 = stk.top();
                    stk.pop();
                    c2 = stk.top();
                    stk.pop();
                    stk.push(to_string(stoi(c1) + stoi(c2)));
                } else if (s == "-") {
                    c1 = stk.top();
                    stk.pop();
                    c2 = stk.top();
                    stk.pop();
                    stk.push(to_string(stoi(c2) - stoi(c1)));
                } else if (s == "*") {
                    c1 = stk.top();
                    stk.pop();
                    c2 = stk.top();
                    stk.pop();
                    stk.push(to_string(stoi(c1) * stoi(c2)));
                } else {
                    c1 = stk.top();
                    stk.pop();
                    c2 = stk.top();
                    stk.pop();
                    stk.push(to_string(stoi(c2) / stoi(c1)));
                }
            } else {
                stk.push(s);
            }
        }
        return stoi(stk.top());
    }
};
