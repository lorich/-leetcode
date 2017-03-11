// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/
// 

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > vecRes;
    	for (int i = 0; i < numRows; ++i)
    	{
    		vector<int> vecLine;
    		vecLine.push_back(1);
    		for (int j = 1; j < i; ++j)
    		{
    			vecLine.push_back(vecRes[i-1][j-1] + vecRes[i-1][j]);
    		}
    		if (i)
    		{
    			vecLine.push_back(1);
    		}
    		vecRes.push_back(vecLine);
    	}
    	return vecRes;
    }
};

/*
Given numRows, generate the first numRows of Pascal's triangle. For example, given numRows = 5, Return 
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 Subscribe to see which companies asked this question. Show Tags Array Show Similar Problems (E) Pascal's Triangle II
*/
