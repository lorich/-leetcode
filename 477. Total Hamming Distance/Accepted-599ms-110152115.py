class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a=[0 for x in range(32)]
        for num in nums:
            index = 0
            while num>0:
                a[index] += num & 0x1
                index = index+1
                num >>= 1
        t=len(nums)
        return sum(i*(t-i) for i in a)

print(Solution().totalHammingDistance([4, 14, 2]))