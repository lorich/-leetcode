// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/
// 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> vecPre;
        vector<int> vecCur;
    	for (int i = 0; i <= rowIndex; ++i)
    	{
            vecCur.clear();
    		vecCur.push_back(1);
    		for (int j = 1; j < i; ++j)
    		{
    			vecCur.push_back(vecPre[j-1] + vecPre[j]);
    		}
    		if (i)
    		{
    			vecCur.push_back(1);
    		}
            swap(vecPre, vecCur);
    	}
    	return vecPre;
    }
};

/*
Given an index k, return the kth row of the Pascal's triangle. For example, given k = 3, Return [1,3,3,1]. Note: Could you optimize your algorithm to use only O(k) extra space? Subscribe to see which companies asked this question. Show Tags Array Show Similar Problems (E) Pascal's Triangle
*/
