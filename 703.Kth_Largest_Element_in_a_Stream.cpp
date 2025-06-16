#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (int i = 0; i < nums.size(); ++i) {
      this->pq.push(nums[i]);
    }
  }

  int add(int val) {
    this->pq.push(val);
    while (this->pq.size() > k) {
      this->pq.pop();
    }
    return this->pq.top();
  }
};
