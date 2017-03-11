// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 

int minLocal(int a, int b)
{
	return a < b ? a : b;
}

int findMinSE(int num[], int start, int end) 
{
	if(num[start] <= num[end])
		return num[start];
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
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element. You may assume no duplicate exists in the array. Subscribe to see which companies asked this question. Show Tags Array Binary Search Show Similar Problems (M) Search in Rotated Sorted Array (H) Find Minimum in Rotated Sorted Array II
*/
