// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/
// 

int singleNumber(int A[], int n) 
{
	int one=0, two=0, three=0;
	int i;
	for (i = 0; i < n; ++i)
	{
		two |= one & A[i];
		one ^= A[i];
		three = one & two;
		one &= ~three;
		two &= ~three;
	}   
	return one;
}

/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (E) Single Number (M) Single Number III
*/
