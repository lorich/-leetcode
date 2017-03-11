// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> setUniq;
        size_t nSize = nums.size();
        for (size_t i = 0; i < nSize; ++i)
        {
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
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. Subscribe to see which companies asked this question. Show Tags Array Hash Table Show Similar Problems (E) Contains Duplicate II (M) Contains Duplicate III
*/
