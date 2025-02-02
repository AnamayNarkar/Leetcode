//go:build ignore

package main

func findDuplicate(nums []int) int {
    myMap := make(map[int]int)
    for _,element:= range(nums){
        if myMap[element]==1{
            return element
        }
        myMap[element]=1
    }
    return -1
}

// constant space solution
// floyds algorithm

func findDuplicate2(nums []int) int {
    
    slow,fast,slow2 := 0,0,0

    for{
        slow=nums[slow]
        fast=nums[nums[fast]]
        if slow==fast{
            break
        }
    }

    for nums[slow]!=nums[slow2]{
        slow=nums[slow]
        slow2=nums[slow2]
    }
    return nums[slow]

}