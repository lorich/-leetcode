// 327. Count of Range Sum
// https://leetcode.com/problems/count-of-range-sum/
// 


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	int iRes = 0;
    	multiset<long long> msSum;
    	long long ddwSum = 0;
    	msSum.insert(ddwSum);
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		ddwSum += nums[i];
    		iRes += distance(msSum.lower_bound(ddwSum-upper), msSum.upper_bound(ddwSum-lower));
    		msSum.insert(ddwSum);
    	}
    	return iRes;
    }
};

/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive. Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive. Note: A naive algorithm of O(n2) is trivial. You MUST do better than that. Example: Given nums = [-2, 5, -1], lower = -2, upper = 2, Return 3. The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2. Credits: Special thanks to @dietpepsi for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Divide and Conquer Binary Search Tree Show Similar Problems (H) Count of Smaller Numbers After Self
*/
