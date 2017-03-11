// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// 

int minSubArrayLen(int s, int* nums, int numsSize) 
{
	if (numsSize <= 0)
	{
		return 0;
	}
	int * sum = (int*)malloc(sizeof(int)*(numsSize+1));
	sum[0] = 0;
	for (int i = 1; i <= numsSize; ++i)
	{
		sum[i] = sum[i-1]+nums[i-1];
	}
	if (sum[numsSize] < s)
	{
		return 0;
	}
	int iRes = numsSize;
	int end = numsSize, start = numsSize-1;
	while(start >= 0)
	{
		while(start >= 0 && sum[end] - sum[start] < s)start--;
		while(sum[end] - sum[start] >= s)end--;
		end++;
		iRes = end-start < iRes ? end-start : iRes;
		start--;
	}
	return iRes;
}

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead. For example, given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint. click to show more practice. More practice: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). Credits: Special thanks to @Freezen for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Array Two Pointers Binary Search Show Similar Problems (H) Minimum Window Substring (M) Maximum Size Subarray Sum Equals k
*/
