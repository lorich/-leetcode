// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// 


int minLocal(int a, int b)
{
	return a < b ? a : b;
}

int findMinSE(int num[], int start, int end) 
{
	if(start == end)
		return num[start];
	if (num[start] == num[end])
	{
		return findMinSE(num, start+1, end);
	}
	int mid = (start + end) >> 1;
	if(num[start] <= num[mid] && num[mid+1] <= num[end])
	{
		return minLocal(num[start], num[mid+1]);
	}
	else if(num[start] <= num[mid])
	{
		return findMinSE(num, mid+1, end);
	}
	else
	{
		return findMinSE(num, start, mid);
	}
}

int findMin(int num[], int n) 
{
    return findMinSE(num, 0, n-1);
}

/*
Follow up for "Find Minimum in Rotated Sorted Array": What if duplicates are allowed? Would this affect the run-time complexity? How and why? Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element. The array may contain duplicates. Subscribe to see which companies asked this question. Show Tags Array Binary Search Show Similar Problems (M) Find Minimum in Rotated Sorted Array
*/
