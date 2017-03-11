// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
// 

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int maxProduct(int A[], int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	int maxLocalPre = A[0], minLocalPre = A[0], maxLocalCur = A[0],  minLocalCur = A[0], maxGlobal = A[0];
	int i;
	for (i = 1; i < n; ++i)
	{
		maxLocalCur = MAX(MAX(maxLocalPre*A[i], A[i]), minLocalPre*A[i]);
		minLocalCur = MIN(MIN(maxLocalPre*A[i], A[i]), minLocalPre*A[i]);
		if (maxLocalCur > maxGlobal)
		{
			maxGlobal = maxLocalCur;
		}
		maxLocalPre = maxLocalCur;
		minLocalPre = minLocalCur;
	}
	return maxGlobal;
}

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product. For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6. Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming Show Similar Problems (E) Maximum Subarray (E) House Robber (M) Product of Array Except Self
*/
