#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        void helper(vector<int>&nums, vector<vector<int>>& finalAns,vector<int>& curr,int index){
            if(index>nums.size()-1){// all elements iterated
                finalAns.push_back(curr);
                return;
            }
    
            //exclude
            helper(nums,finalAns,curr,index+1);
    
            //include
            curr.push_back(nums[index]);
            helper(nums,finalAns,curr,index+1);
            curr.pop_back();
        }   
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>finalAns;
            vector<int> currVector;
            helper(nums,finalAns,currVector,0);
            return finalAns;
        }
    
};
        