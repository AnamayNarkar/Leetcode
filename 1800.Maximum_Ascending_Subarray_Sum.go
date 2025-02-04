//go:build ignore

package main

func max(a,b int) int{
    if a>b{
        return a
    }
    return b
}

func maxAscendingSum(nums []int) int {
    currSum:=nums[0]
    maxSum:=nums[0]
    for i:=1;i<len(nums);i++{
        if nums[i-1]<nums[i] {
            currSum+=nums[i]
        }else{
            currSum=nums[i]
        }
        maxSum = max(currSum,maxSum);
    }
    return maxSum
}