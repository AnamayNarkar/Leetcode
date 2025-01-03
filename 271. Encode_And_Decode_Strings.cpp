// === my solution ===
// time complexity: O(n)
// space complexity: O(n)
// works on neetcode didn't check on leetcode

class Solution {
  public:
    int helper(vector<int> decimalPlaces) { return decimalPlaces[0] * 100 + decimalPlaces[1] * 10 + decimalPlaces[2]; }

    string encode(vector<string> &strs) {
        string ans = "";
        string flag;
        string digitToAdd;
        for (string s : strs) {
            if (s.length() < 10) {
                flag = "00";
            } else if (s.length() < 100) {
                flag = "0";
            } else {
                flag = "";
            }
            ans += flag + to_string(s.length()) + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int index = 0;
        int nextWordLength;
        string tempStr;
        vector<int> decimalPlaces(3);
        while (index < s.length()) {
            tempStr = "";
            decimalPlaces[0] = s[index] - '0';
            decimalPlaces[1] = s[index + 1] - '0';
            decimalPlaces[2] = s[index + 2] - '0';
            nextWordLength = helper(decimalPlaces);
            for (int i = index + 3; i <= index + 2 + nextWordLength; i++) {
                tempStr += s[i];
            }
            ans.push_back(tempStr);
            index += nextWordLength + 3;
        }
        return ans;
    }
};