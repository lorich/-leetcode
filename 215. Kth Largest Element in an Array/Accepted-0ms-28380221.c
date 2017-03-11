// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// 

void swap(int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void heapAdjust(int * heap, int s, int size)
{
	if (!(s<size))return;
	for (int i = (s+1)*2-1; i < size; i=(i+1)*2-1)
	{
		//小顶堆
		if (i+1 < size && heap[i+1] < heap[i]) i++;
		if (!(heap[s]>heap[i])) break;
		swap(&heap[s], &heap[i]);
		s=i;
	}
}

int findKthLargest(int* nums, int numsSize, int k) 
{
	for (int i = k/2-1; i >= 0; --i)
	{
		heapAdjust(nums, i, k);
	}
	//printIt(nums, numsSize);

	for (int i = k; i < numsSize; ++i)
	{
		if (nums[i] > nums[0])
		{
			nums[0] = nums[i];
			heapAdjust(nums, 0, k);
		}
		//printIt(nums, numsSize);
	}
	return nums[0];
}

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. For example, Given [3,2,1,5,6,4] and k = 2, return 5. Note: You may assume k is always valid, 1 ≤ k ≤ array's length. Credits: Special thanks to @mithmatt for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Heap Divide and Conquer Show Similar Problems (M) Wiggle Sort II (M) Top K Frequent Elements (E) Third Maximum Number
*/
