# 367. Valid Perfect Square
# https://leetcode.com/problems/valid-perfect-square/
# 

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        r=1.0
        while abs(r*r-x)>1e-1:
            r=(r+x/r)/2
        return int(r)

    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        sqrtNum=Solution.mySqrt(self, num)
        return num-sqrtNum*sqrtNum < 1e-9

'''
Given a positive integer num, write a function which returns True if num is a perfect square else False. Note: Do not use any built-in library function such as sqrt. Example 1: 
Input: 16
Returns: True
 Example 2: 
Input: 14
Returns: False
 Credits: Special thanks to @elmirap for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Binary Search Math Show Similar Problems (E) Sqrt(x)
'''
