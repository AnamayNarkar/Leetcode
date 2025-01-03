#include <bits/stdc++.h>
using namespace std;

// === TLE ===

class Solution {
  public:
    bool isAnagram(string str1, string str2) {
        if (str1.length() != str2.length()) {
            return false;
        }

        unordered_map<char, int> myMap;
        for (int i = 0; i < str1.length(); i++) {
            myMap[str1[i]]++;
            myMap[str2[i]]--;
        }

        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        unordered_set<int> notToBeIncludedStringsIndexes;
        vector<vector<string>> ans;
        vector<string> temp;
        for (int i = 0; i < strs.size(); i++) {
            if (notToBeIncludedStringsIndexes.find(i) != notToBeIncludedStringsIndexes.end()) {
                continue;
            }
            for (int j = i + 1; j < strs.size(); j++) {
                if (notToBeIncludedStringsIndexes.find(j) == notToBeIncludedStringsIndexes.end() && isAnagram(strs[i], strs[j])) {
                    notToBeIncludedStringsIndexes.insert(j);
                    temp.push_back(strs[j]);
                }
            }
            notToBeIncludedStringsIndexes.insert(i);
            temp.push_back(strs[i]);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

// === Working ===

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        unordered_map<string, vector<string>> myMap;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            myMap[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

// time complexity: O(n*mlogm) where n is the number of strings and m is the length of the string
// because we are sorting each string and each string has length m and we are doing this n times
// space complexity: O(n*m)

// === Better ===

class Solution {
  public:
    string getCharCountString(string str) {
        vector<int> charCount(26, 0);
        for (int i = 0; i < str.length(); i++) {
            charCount[str[i] - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < 26; i++) {
            ans = ans + " " + to_string(charCount[i]);
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        unordered_map<string, vector<string>> myMap;

        for (int i = 0; i < strs.size(); i++) {
            string temp = getCharCountString(strs[i]);
            myMap[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

// here for the key of the hashmap we are using the count of each character in the string which takes O(m*26) time
// Time complexity: O(n*m*26) which simplifies to O(n*m) where n is the number of strings and m is the length of the string