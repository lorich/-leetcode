# 268. Missing Number
# https://leetcode.com/problems/missing-number/
# 

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        i=0
        for val in nums:
            i=i+1
            res=res+i-val
        return res

'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array. For example, Given nums = [0, 1, 3] return 2. Note: Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? Credits: Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Array Math Bit Manipulation Show Similar Problems (H) First Missing Positive (E) Single Number (M) Find the Duplicate Number
'''
