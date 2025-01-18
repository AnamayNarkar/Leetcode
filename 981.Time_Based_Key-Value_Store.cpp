#include <bits/stdc++.h>
using namespace std;

class TimeMap {
  private:
    unordered_map<string, vector<pair<int, string>>> map;

  public:
    TimeMap() {
        //    this->map = new unordered_map<string, vector<pair<int, string>>>;
    }

    void set(string key, string value, int timestamp) {
        if (this->map.find(key) == this->map.end()) {
            this->map[key] = vector<pair<int, string>>();
        }
        this->map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (this->map.find(key) == this->map.end()) {
            return "";
        } else {

            int left = 0;
            int right = this->map[key].size() - 1;
            int mid;

            while (left <= right) {
                mid = left + (right - left) / 2;
                if (this->map[key].at(mid).first == timestamp) {
                    return this->map[key].at(mid).second;
                } else if (this->map[key].at(mid).first > timestamp) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (right >= 0) {
                return this->map[key].at(right).second;
            } else {
                return "";
            }
        }
    }
};
