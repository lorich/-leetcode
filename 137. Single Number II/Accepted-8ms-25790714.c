// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/
// 

int singleNumber(int A[], int n) 
{
	int intLen = sizeof(int)*8;
	int res = 0;
	int i, j, counter;
	for (i = 0; i < intLen; ++i)
	{
		counter = 0;
		for (j = 0; j < n; ++j)
		{
			counter += (A[j]>>i)&1;
		}
		res |= (counter%3)<<i;
	}
	return res;
}

/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (E) Single Number (M) Single Number III
*/
