#include <bits/stdc++.h>
using namespace std;

namespace mynamespace {
struct any {
  int pointIndex;
  double distance;

  any(int p, double d) {
    this->pointIndex = p;
    this->distance = d;
  }
};
} // namespace mynamespace

struct customComparator {
  bool operator()(mynamespace::any any1, mynamespace::any any2) {
    return any1.distance > any2.distance;
  }
};

class Solution {
private:
  double eucledianDistance(int x1, int x2, int y1, int y2) {
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
  }

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> finalAns(k);
    priority_queue<mynamespace::any, vector<mynamespace::any>, customComparator>
        pq;
    for (int i = 0; i < points.size(); i++) {
      pq.push(mynamespace::any(
          i, eucledianDistance(0, points[i][0], 0, points[i][1])));
    }
    for (int i = 0; i < k; ++i) {
      finalAns[i] = points.at(pq.top().pointIndex);
      pq.pop();
    }
    return finalAns;
  }
};
