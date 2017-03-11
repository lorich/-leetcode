// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// 

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
    	string prefix("");
    	int minLen;
    	if (!strs.empty() && !strs[0].empty())
    	{
    		minLen = strs[0].size();
    		for (int i = 1; i < strs.size(); ++i)
    		{
    			if (strs[i].empty())
    			{
    				return prefix;
    			}
    			minLen = min(minLen, (int)strs[i].size());
    			for (int j = 0; j < minLen; ++j)
    			{
    				if (strs[i][j] != strs[0][j])
    				{
    					minLen = j;
    					break;
    				}
    			}
    		}
    		prefix = strs[0].substr(0, minLen);
    	}
    	return prefix;
    }
};

/*
Write a function to find the longest common prefix string amongst an array of strings. Subscribe to see which companies asked this question. Show Tags String
*/
