// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// 

double findKthNum(int A[], int m, int B[], int n, int k)
{
    if(m > n)
        return findKthNum(B, n, A, m, k);
    if(k > m + n || k <= 0)
        return 0;
    if(m == 0)
        return B[k-1];
    if(k == 1)
        return A[0] < B[0] ? A[0] : B[0];
    int pa = m < k>>1 ? m : k>>1;
    int pb = k - pa;
    if(A[pa-1] == B[pb-1])
        return A[pa-1];
    else if (A[pa-1] < B[pb-1])
        return findKthNum(A+pa, m-pa, B, n, k-pa);
    else
        return findKthNum(A, m, B+pb, n-pb, k-pb);
}

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if(total&0x01)
            return findKthNum(A, m, B, n, (total>>1)+1);
        else
            return (findKthNum(A, m, B, n, total>>1) + findKthNum(A, m, B, n, (total>>1) + 1))/2.0;
    }
};

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)). Example 1: 
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
 Example 2: 
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 Subscribe to see which companies asked this question. Show Tags Binary Search Array Divide and Conquer
*/
