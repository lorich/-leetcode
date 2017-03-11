// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/
// 

void merge(int* nums1, int m, int* nums2, int n) 
{
    int * num3 = (int*)malloc((m+n)*sizeof(int));
    int i=0, j=0, k=0;
    while(i<m || j<n)
    {
    	if (i<m && j<n)
    	{
    		if(nums1[i] < nums2[j]) 
    		{
    			num3[k++]=nums1[i++];
    		}
    		else
    		{
    			num3[k++]=nums2[j++];
    		}
    	}
    	else if(i<m)
    	{
    		num3[k++]=nums1[i++];
    	}
    	else
    	{
    		num3[k++]=nums2[j++];
    	}
    }
    for (i = 0; i < m+n; ++i)
    {
    	nums1[i] = num3[i];
    	//printf("%d ", nums1[i]);
    }
    //printf("\n");
    free(num3);
}

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array. Note: You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively. Subscribe to see which companies asked this question. Show Tags Array Two Pointers Show Similar Problems (E) Merge Two Sorted Lists
*/
