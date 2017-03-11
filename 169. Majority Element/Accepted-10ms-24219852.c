// 169. Majority Element
// https://leetcode.com/problems/majority-element/
// 

int majorityElement(int num[], int n) 
{
	int maj = num[0];
	int ntimes = 1;
	int i;
	for (i = 1; i < n; ++i)
	{
		if (0 == ntimes)
		{
			maj = num[i];
			ntimes = 1;
		}
		else if (num[i] == maj)
		{
			ntimes++;
		}
		else
		{
			ntimes--;
		}
	}   
	return maj;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. You may assume that the array is non-empty and the majority element always exist in the array. Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Array Divide and Conquer Bit Manipulation Show Similar Problems (M) Majority Element II
*/
