# 231. Power of Two
# https://leetcode.com/problems/power-of-two/
# 

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and 1073741824%n == 0
        

'''
Given an integer, write a function to determine if it is a power of two. Credits: Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Math Bit Manipulation Show Similar Problems (E) Number of 1 Bits (E) Power of Three (E) Power of Four
'''
