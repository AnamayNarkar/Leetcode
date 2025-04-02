#include <bits/stdc++.h>
using namespace std;

// O(n^2) solution

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int i=nums[0];
            for(int j=0;j<nums.size()-1;++j){
                if(nums[j]>i){
                    i=nums[j];
                    continue;
                }
                for(int k=j+1;k<nums.size();++k){
                    ans = max(ans,(long long)(i-nums[j])*nums[k]);
                }
            }
            return ans;
        }
    };


// O(n) solution

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int i_max=nums[0];
            int diff_max=0;
            for(int k=0;k<nums.size();++k){
                ans = max(ans,(long long)diff_max*nums[k]);
                diff_max = max(diff_max,i_max-nums[k]);
                i_max= max(i_max,nums[k]);
            }
            return ans;
        }
    };