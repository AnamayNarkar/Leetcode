from typing import List


# // Permutations
# //
# // Given an array nums of unique integers, return all the possible permutations.
# // You may return the answer in any order.
# //
# // Example 1:
# //
# // Input: nums = [1,2,3]
# //
# // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
# //
# // Example 2:
# //
# // Input: nums = [7]
# //
# // Output: [[7]]
# //
# // Constraints:
# //
# //     1 <= nums.length <= 6
# //     -10 <= nums[i] <= 10
#
class Solution:
    def adder(self, nums: List[List[int]], num: int) -> List[List[int]]:
        final: List[List[int]] = []
        for tmpList in nums:
            for i in range(0, len(tmpList) + 1):
                copy = tmpList.copy()
                copy.insert(i, num)
                final.append(copy)
        return final

    def helper(self, nums: List[int]) -> List[List[int]]:
        # base case
        if len(nums) == 1:
            return [[nums[0]]]

        val: List[List[int]] = self.helper(nums[1:])
        return self.adder(val, nums[0])

    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        elif len(nums) == 0:
            return [[]]
        val: List[List[int]] = self.helper(nums[1:])
        return self.adder(val, nums[0])
