# Majority Element
# https://leetcode.com/problems/majority-element/

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for i in set(nums):
            if nums.count(i) > (len(nums) // 2):
                return i