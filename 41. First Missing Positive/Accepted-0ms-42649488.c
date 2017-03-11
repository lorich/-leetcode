// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
// 

void swap(int* a, int* b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
int firstMissingPositive(int* nums, int numsSize) 
{
	for (int i = 0; i < numsSize;)
	{
		if (nums[i] > 0 && nums[i] <= numsSize && nums[i] != i+1 && nums[i] != nums[nums[i]-1])
		{
			swap(&nums[i], &nums[nums[i]-1]);
		}
		else
		{
			++i;
		}
	}

	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != i+1)
		{
			return i+1;
		}
	}
	return numsSize+1;
}

/*
Given an unsorted integer array, find the first missing positive integer. For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2. Your algorithm should run in O(n) time and uses constant space. Subscribe to see which companies asked this question. Show Tags Array Show Similar Problems (E) Missing Number (M) Find the Duplicate Number (E) Find All Numbers Disappeared in an Array
*/
