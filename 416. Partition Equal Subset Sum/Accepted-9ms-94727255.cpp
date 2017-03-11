// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset < MAX_NUM * MAX_ARRAY_SIZE / 2 + 1 > bsAccess(1);    //'0' is always accessible
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bsAccess |= bsAccess << n;      //用批量左移替换逐个加，brilliant
        }
        return !(sum % 2) && bsAccess[sum / 2];
    }
};

/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal. Note: Each of the array element will not exceed 100. The array size will not exceed 200. Example 1: 
Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 Example 2: 
Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 Subscribe to see which companies asked this question. Show Tags Dynamic Programming
*/
