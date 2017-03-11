// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/
// 

class Solution {
public:
	vector<string> m_vecRes;
	string vec2str(const vector<string>& vecLine)
	{
		string strRes;
		if (vecLine.empty())
		{
			return strRes;
		}
		strRes = vecLine[0];
		size_t nSize = vecLine.size();
		for (size_t i = 1; i < nSize; ++i)
		{
			strRes += " " + vecLine[i];
		}
		return strRes;
	}
	void calWordBreak(const string& s, const unordered_set<string>& wordDict, vector<string>& vecLine)
	{
		if (s.empty())
		{
			m_vecRes.push_back(vec2str(vecLine));
			return;
		}
		size_t nSize = s.size();
        for (size_t i = 1; i <= nSize; ++i)
        {
            string strSub = s.substr(0, i);
            if (wordDict.find(strSub) != wordDict.end())
            {
                vecLine.push_back(strSub);
                calWordBreak(s.substr(i), wordDict, vecLine);
                vecLine.pop_back();
            }
        }
	}
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        m_vecRes.clear();
        if (!s.empty())
        {
        	vector<string> vecLine;
        	calWordBreak(s, wordDict, vecLine);
        }
        return m_vecRes;
    }
};

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words. Return all such possible sentences. For example, given s = "catsanddog", dict = ["cat", "cats", "and", "sand", "dog"]. A solution is ["cats and dog", "cat sand dog"]. UPDATE (2017/1/4): The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Backtracking Show Similar Problems (M) Word Break (H) Concatenated Words
*/
