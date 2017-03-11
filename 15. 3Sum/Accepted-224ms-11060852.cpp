// 15. 3Sum
// https://leetcode.com/problems/3sum/
// 

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
    	vector<vector<int> > result;
    	if (num.size() < 3)
    	{
    		return result;
    	}
    	sort(num.begin(), num.end());
    	for (int i = 0; i < num.size(); ++i)
    	{
    		if (i > 0 && num[i] == num[i-1])
    		{
    			continue;
    		}
    		int j=i+1, k=num.size()-1;
    		while(j < k)
    		{
    			if (j > i+1 && num[j] == num[j-1])
    			{
    				j++;
    				continue;
    			}
    			if (num[i] + num[j] == -num[k])
    			{
    				vector<int> vecLine;
    				vecLine.push_back(num[i]);
    				vecLine.push_back(num[j]);
    				vecLine.push_back(num[k]);
    				result.push_back(vecLine);
    				j++, k--;
    			}
    			else if (num[i] + num[j] < -num[k])
    			{
    				j++;
    			}
    			else
    			{
    				k--;
    			}
    		}
    		
    	}
    	return result;
    }
};

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero. Note: The solution set must not contain duplicate triplets. 
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 Subscribe to see which companies asked this question. Show Tags Array Two Pointers Show Similar Problems (E) Two Sum (M) 3Sum Closest (M) 4Sum (M) 3Sum Smaller
*/
