// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// 

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
     	{
     		return s;
     	}
     	int iLen = s.length();
     	int iBegin = 0, iMaxLen = 1;
     	bool isPal[1000][1000]={false};
     	for (int i = 0; i < iLen; ++i)
     	{
     		isPal[i][i] = true;
     	}
     	for (int i = 0; i < iLen-1; ++i)
     	{
     		if (s[i] == s[i+1])
     		{
     			iBegin = i;
     			iMaxLen = 2;
     			isPal[i][i+1] = true;
     		}
     	}
     	for (int len = 3; len <= iLen; ++len)
     	{
     		for (int begin = 0; begin < iLen-len+1; ++begin)
     		{
     			int end = begin+len-1;
     			if (s[begin] == s[end] && isPal[begin+1][end-1])
     			{
     				iBegin = begin;
     				iMaxLen = len;
     				isPal[begin][end] = true;
     			}
    
     		}
     	}
     	return s.substr(iBegin, iMaxLen);  
    }
};

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000. Example: 
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 Example: 
Input: "cbbd"

Output: "bb"
 Subscribe to see which companies asked this question. Show Tags String Show Similar Problems (H) Shortest Palindrome (E) Palindrome Permutation (H) Palindrome Pairs (M) Longest Palindromic Subsequence
*/
