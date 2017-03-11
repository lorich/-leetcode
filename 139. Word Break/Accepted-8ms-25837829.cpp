// 139. Word Break
// https://leetcode.com/problems/word-break/
// 

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
    	size_t nSize = s.size();
    	bool bFlag[nSize+1];
    	//bool * bFlag = new bool[nSize+1];
    	memset(bFlag, 0, nSize+1);
    	bFlag[0] = true;
    	for (size_t i = 1; i <= nSize; ++i)
    	{
    		const string strCurSub = s.substr(0, i);
    		if (wordDict.find(strCurSub) != wordDict.end())
    		{
    			bFlag[i] = true;
    			continue;
    		}
    		for (size_t j = i-1; j > 0; --j)
    		{
    			if (wordDict.find(strCurSub.substr(j)) != wordDict.end() && bFlag[j])
    			{
    				bFlag[i] = true;
    				break;
    			}
    		}
    	}
    	return bFlag[nSize];
    }
};


/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words. For example, given s = "leetcode", dict = ["leet", "code"]. Return true because "leetcode" can be segmented as "leet code". UPDATE (2017/1/4): The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Show Similar Problems (H) Word Break II
*/
