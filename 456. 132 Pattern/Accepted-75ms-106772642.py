import sys

class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        stackmaxsofar, secondmaxsofar = [], -sys.maxsize-1
        for i in nums[::-1]:
        	if i < secondmaxsofar:
        		return True
        	else:
        		while stackmaxsofar and i > stackmaxsofar[-1]:
        			secondmaxsofar=stackmaxsofar.pop()
        	stackmaxsofar.append(i)
        return False
		
print(Solution().find132pattern([1,2,3,4]))