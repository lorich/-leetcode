# 343. Integer Break
# https://leetcode.com/problems/integer-break/
# 

class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        mp=[0,0,1]
        for i in xrange(3,n+1):
        	lefte=2*max(mp[i-2],i-2)
        	righte=3*max(mp[i-3],i-3)
        	mp.append(max(lefte, righte))
        #print mp
        return mp[n]

'''
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get. For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4). Note: You may assume that n is not less than 2 and not larger than 58. There is a simple O(n) solution to this problem. You may check the breaking results of n ranging from 7 to 10 to discover the regularities. Credits: Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Math
'''
