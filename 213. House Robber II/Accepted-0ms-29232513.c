// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/
// 

int robIt(int *num, int n) 
{
	int* rob = (int*)malloc(n * sizeof(int));
	rob[0] = num[0];
	rob[1] = num[0] > num[1] ? num[0] : num[1];
	for (int i = 2; i < n; ++i)
	{
		rob[i] = num[i] + rob[i-2] > rob[i-1] ? num[i] + rob[i-2] : rob[i-1];
	}
	int iRes = rob[n-1];
	free(rob);
	return iRes;
}

#define MAX(a,b) (a)>(b)?(a):(b)
int rob(int* nums, int numsSize) 
{
	if (numsSize <= 0)
	{
		return 0;
	}
	if (1 == numsSize)
	{
		return nums[0];
	}
	if (2 == numsSize)
	{
		return MAX(nums[0], nums[1]);
	}
	int * numsNew = (int*)malloc((numsSize+1)*sizeof(int)); 
	memcpy(numsNew, nums, numsSize*sizeof(int));  
	numsNew[numsSize] = nums[0];
	int robStart0 = robIt(numsNew, numsSize-1);
	int robStart1 = robIt(&numsNew[1], numsSize-1);
	int robStart2 = robIt(&numsNew[2], numsSize-1);
	free(numsNew);
	return MAX(robStart0, MAX(robStart1, robStart2));
}

/*
Note: This is an extension of House Robber. After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. Credits: Special thanks to @Freezen for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Show Similar Problems (E) House Robber (E) Paint House (E) Paint Fence (M) House Robber III
*/
