// 132. Palindrome Partitioning II
// https://leetcode.com/problems/palindrome-partitioning-ii/
// 

class Solution {
public:
    int minCut(string s) {
    	if (s.empty())
    	{
    		return 0;
    	}
    	int iRes = 0;
    	size_t nLen = s.size();
    	bool ** isPal = new bool *[nLen];
    	for (int i = 0; i < nLen; ++i)
    	{
    		isPal[i] = new bool[nLen];
    	}
    	int* minCut = new int[nLen];
    	for (int i = 0; i < nLen; ++i)
    	{
    		minCut[i] = i;
    		for (int j = i; j >= 0; --j)
    		{
    			bool isPalindromeJI = (s[i] == s[j]) && (i - j <= 2 || isPal[j+1][i-1]);
    			isPal[j][i] = isPalindromeJI;
    			if (isPalindromeJI)
    			{
    				if (j == 0)
    				{
    					minCut[i] = 0;
    				}
    				else
    				{
    					minCut[i] = min(minCut[i], minCut[j-1] + 1);
    				}
    			}
    		}
    	}
    	iRes = minCut[nLen-1];
    	for (int i = 0; i < nLen; ++i)
    	{
    		delete isPal[i];
    	}
    	delete minCut;
    	return iRes;
    }
};

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of s. For example, given s = "aab", Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Show Similar Problems (M) Palindrome Partitioning
*/
