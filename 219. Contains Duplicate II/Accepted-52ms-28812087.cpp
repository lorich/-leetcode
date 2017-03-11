// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/
// 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> setUniq;
        size_t nSize = nums.size();
        for (size_t i = 0; i < nSize; ++i)
        {
        	if (i > k)
        	{
        		setUniq.erase(nums[i-k-1]);
        	}
        	if (setUniq.find(nums[i]) != setUniq.end())
        	{
        		return true;
        	}
        	setUniq.insert(nums[i]);
        }
        return false;
    }
};


/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k. Subscribe to see which companies asked this question. Show Tags Array Hash Table Show Similar Problems (E) Contains Duplicate (M) Contains Duplicate III
*/
