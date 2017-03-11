# 69. Sqrt(x)
# https://leetcode.com/problems/sqrtx/
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

'''
Implement int sqrt(int x). Compute and return the square root of x. Subscribe to see which companies asked this question. Show Tags Binary Search Math Show Similar Problems (M) Pow(x, n) (E) Valid Perfect Square
'''
