// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// 

void localSwap(int *a, int *b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}

void moveZeroes(int* nums, int numsSize) 
{
    int iIndexZero = 0, iIndexNotZero = 0;
    while(iIndexZero < numsSize && iIndexNotZero < numsSize)
    {
    	while(nums[iIndexZero] != 0 && iIndexZero < numsSize)iIndexZero++;
    	while(nums[iIndexNotZero] == 0 && iIndexZero < numsSize)iIndexNotZero++;
    	if (iIndexZero < numsSize && iIndexNotZero < numsSize && iIndexNotZero > iIndexZero)
    	{
    		localSwap(&nums[iIndexZero], &nums[iIndexNotZero]);
    	}
    	else
    	{
    		iIndexNotZero = iIndexZero+1;
    	}
    }
}

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. Note: You must do this in-place without making a copy of the array. Minimize the total number of operations. Credits: Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Array Two Pointers Show Similar Problems (E) Remove Element
*/
