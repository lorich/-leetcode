// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// 

class Solution {
public:
    int maxSubArray(int A[], int n) 
    {
    	if(n <= 0)
    	{
    		return 0;
    	}
    	int iCur=0, iMax=A[0];   
    	for (int i = 0; i < n; ++i)
    	{
    		if (iCur >= 0)
    		{
    			iCur += A[i];
    		}
    		else
    		{
    			iCur = A[i];
    		}
    		if (iCur > iMax)
    		{
    			iMax = iCur;
    		}
    	}
    	return iMax;
    }
};

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum. For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6. click to show more practice. More practice: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming Divide and Conquer Show Similar Problems (E) Best Time to Buy and Sell Stock (M) Maximum Product Subarray
*/
