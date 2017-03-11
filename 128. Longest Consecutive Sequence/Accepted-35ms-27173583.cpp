// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int iRes = 0;
        unordered_map<int, int> mapRange;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            const int iCur = nums[i];
            if (mapRange.find(iCur) == mapRange.end())
            {
                mapRange[iCur] = iCur;
                int iLeft = iCur, iRight = iCur;
                if (mapRange.find(iCur-1) != mapRange.end())
                {
                    iLeft = mapRange[iCur-1];
                }
                if (mapRange.find(iCur+1) != mapRange.end())
                {
                    iRight = mapRange[iCur+1];
                }
                mapRange[iLeft] = iRight;
                mapRange[iRight] = iLeft;
                iRes = iRight - iLeft + 1 > iRes ? iRight - iLeft + 1: iRes;
            }
        }
        return iRes;
    }
};

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence. For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. Your algorithm should run in O(n) complexity. Subscribe to see which companies asked this question. Show Tags Array Union Find Show Similar Problems (M) Binary Tree Longest Consecutive Sequence
*/
