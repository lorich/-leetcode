// 198. House Robber
// https://leetcode.com/problems/house-robber/
// 

int rob(int num[], int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	if (1 == n)
	{
		return num[0];
	}
	int* rob = (int*)malloc(n * sizeof(int));
	rob[0] = num[0];
	rob[1] = num[0] > num[1] ? num[0] : num[1];
	int i;
	for (i = 2; i < n; ++i)
	{
		rob[i] = num[i] + rob[i-2] > rob[i-1] ? num[i] + rob[i-2] : rob[i-1];
	}
	return rob[n-1];
}

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. Credits: Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Show Similar Problems (M) Maximum Product Subarray (M) House Robber II (E) Paint House (E) Paint Fence (M) House Robber III
*/
