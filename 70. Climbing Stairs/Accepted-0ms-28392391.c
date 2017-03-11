// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
// 

int climbStairs(int n) 
{
	if (!(n>0))return -1;
	int pre0=1, pre1=1;
	for (int i = 2; i <= n; ++i)
	{
		int cur = pre0+pre1;
		pre0 = pre1;
		pre1 = cur;
	}
	return pre1;
}

/*
You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? Note: Given n will be a positive integer. Subscribe to see which companies asked this question. Show Tags Dynamic Programming
*/
