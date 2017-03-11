# 342. Power of Four
# https://leetcode.com/problems/power-of-four/
# 

class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num>0 and num&(num-1)==0 and (num-1)%3==0

'''
Given an integer (signed 32 bits), write a function to check whether it is a power of 4. Example: Given num = 16, return true. Given num = 5, return false. Follow up: Could you solve it without loops/recursion? Credits: Special thanks to @yukuairoy for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (E) Power of Two (E) Power of Three
'''
