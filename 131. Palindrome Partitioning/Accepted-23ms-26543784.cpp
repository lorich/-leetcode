// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/
// 

class Solution {
public:
	vector<vector<string> > m_vecRes;
    bool isPalindrome(const string& s)
    {
    	size_t i = 0, j = s.size() -1;
    	while(i < j && s[i] == s[j])
    	{
    		i++;
    		j--;
    	}
    	return i >= j;
    }
    void calPalindrome(const string& s, vector<string>& vecLine)
    {
        if (s.empty())
        {
            m_vecRes.push_back(vecLine);
            return;
        }
        size_t nSize = s.size();
        for (size_t i = 1; i <= nSize; ++i)
        {
            string sub = s.substr(0, i);
            if (isPalindrome(sub))
            {
                vecLine.push_back(sub);
                calPalindrome(s.substr(i), vecLine);
                vecLine.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) 
    {
        m_vecRes.clear();
    	if (!s.empty())
    	{
            vector<string> vecLine;
    		calPalindrome(s, vecLine);
    	}
    	return m_vecRes;
    }
};

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s. For example, given s = "aab", Return 
[
  ["aa","b"],
  ["a","a","b"]
]
 Subscribe to see which companies asked this question. Show Tags Backtracking Show Similar Problems (H) Palindrome Partitioning II
*/
