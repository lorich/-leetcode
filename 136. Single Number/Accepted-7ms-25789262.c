// 136. Single Number
// https://leetcode.com/problems/single-number/
// 

int singleNumber(int A[], int n) {
    int ret = A[0];
    int i;
    for(i=1; i < n; i++)
    {   
        ret = ret ^ A[i];
    }   
    return ret;
}

/*
Given an array of integers, every element appears twice except for one. Find that single one. Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? Subscribe to see which companies asked this question. Show Tags Hash Table Bit Manipulation Show Similar Problems (M) Single Number II (M) Single Number III (E) Missing Number (M) Find the Duplicate Number (E) Find the Difference
*/
