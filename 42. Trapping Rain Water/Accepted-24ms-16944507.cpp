// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
// 

class Solution 
{
public:
    int trap(int A[], int n) 
    {
        int iWater = 0;
        int iLeft = 0, iRight = n-1;
        while(iLeft < iRight)
        {
        	int iLeftValue = A[iLeft];
        	int iRightValue = A[iRight];
        	int iTemp = 0, iTempValue = 0;
        	if (iLeftValue < iRightValue)
        	{
        		//cal the left of the tallest
        		iTemp = iLeft+1;
        		while(iTemp <= iRight && A[iTemp] < iLeftValue)
        		{
        			iTempValue+=A[iTemp];
        			iTemp++;
        		}
        		if (iTemp <= iRight)
        		{
        			iWater += iLeftValue * (iTemp-iLeft-1) - iTempValue;
        		}
        		iLeft = iTemp;
        	}
        	else
        	{
        		//cal the right of the tallest
        		iTemp = iRight-1;
        		while(iTemp >= iLeft && A[iTemp] < iRightValue)
        		{
        			iTempValue+=A[iTemp];
        			iTemp--;
        		}
        		if (iTemp >= iLeft)
        		{
        			iWater += iRightValue * (iRight-iTemp-1) - iTempValue;
        		}
        		iRight = iTemp;
        	}
        }
        return iWater;
    }
};

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image! Subscribe to see which companies asked this question. Show Tags Array Stack Two Pointers Show Similar Problems (M) Container With Most Water (M) Product of Array Except Self (H) Trapping Rain Water II
*/
