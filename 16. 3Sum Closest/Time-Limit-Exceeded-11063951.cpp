// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/
// 

class Solution {
public:
    int sumClosest(vector<int> &num, int target, int begin, int end)
    {
    	int size = end - begin;
    	if (size < 3)
    	{
    		return 0;
    	}
    
    	int sumMin = num[begin] + num[begin+1] + num[begin+2];
    	if (size == 3 || target <= sumMin)
    	{
    		return sumMin;
    	}
    	int sumMax = num[end-1] + num[end-2] + num[end-3];
    	if (size == 3 || target >= sumMax)
    	{
    		return sumMax;
    	}
    	int sum1 = sumClosest(num, target, begin+1, end);
    	int sum2 = sumClosest(num, target, begin, end-1);
    	return (int)fabs(sum1-target) < (int)fabs(sum2-target) ? sum1 : sum2;
    }
    int threeSumClosest(vector<int> &num, int target)
    {
    	sort(num.begin(), num.end());
    	return sumClosest(num, target, 0, num.size());
    }
};

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution. 
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 Subscribe to see which companies asked this question. Show Tags Array Two Pointers Show Similar Problems (M) 3Sum (M) 3Sum Smaller
*/
