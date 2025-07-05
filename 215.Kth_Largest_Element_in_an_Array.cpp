#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int num:nums){
            pq.push(num);
        }
        int finalAns;
        while(k--){
            finalAns=pq.top();
            pq.pop();
        }
        return finalAns;
    }
};

