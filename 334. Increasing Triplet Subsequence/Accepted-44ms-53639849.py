# 334. Increasing Triplet Subsequence
# https://leetcode.com/problems/increasing-triplet-subsequence/
# 

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        minimum=minimum2=0x7fffffff
        for num in nums:
        	if num <= minimum:		# num <= minimum <= minimum2
        		minimum=num
        	elif num <= minimum2:	# minimum < num <= minimum2
        		minimum2=num
        	else:					# minimum < minimum2 < num
        		return True
    	return False

'''
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. Formally the function should: Return true if there exists i, j, k such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. Your algorithm should run in O(n) time complexity and O(1) space complexity. Examples: Given [1, 2, 3, 4, 5], return true. Given [5, 4, 3, 2, 1], return false. Credits: Special thanks to @DjangoUnchained for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Similar Problems (M) Longest Increasing Subsequence
'''
