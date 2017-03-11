// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// 

#include<algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vecResult;
        vector<int> vecSortNumbers = numbers;
        std:sort(vecSortNumbers.begin(), vecSortNumbers.end());
        size_t i, j;
        for( i = 0, j = vecSortNumbers.size() - 1; i < j;)
        {
            if(vecSortNumbers[i] + vecSortNumbers[j] == target)break;
            else if(vecSortNumbers[i] + vecSortNumbers[j] < target)i++;
            else j--;
        }
        size_t nCouter = 0, nSize = numbers.size();
        int iOtherOne = 0;
        for(size_t nIndex = 0; nIndex < nSize; nIndex++)
        {
            int iCurNum = numbers[nIndex];
            if(nCouter == 1 && iOtherOne == iCurNum) 
            {
                vecResult.push_back(nIndex+1);
                break;
            }
            if(nCouter == 0 && (iCurNum == vecSortNumbers[i] || iCurNum == vecSortNumbers[j]))
            {
                vecResult.push_back(nIndex+1);
                nCouter ++;
                iOtherOne = target - iCurNum;
            }
        }
        return vecResult;    
    }
};

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target. You may assume that each input would have exactly one solution, and you may not use the same element twice. Example: 
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 Subscribe to see which companies asked this question. Show Tags Array Hash Table Show Similar Problems (M) 3Sum (M) 4Sum (E) Two Sum II - Input array is sorted (E) Two Sum III - Data structure design
*/
