// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/
// 

class Solution {
public:
    bool isMatch(const char *source, const char *pattern) 
    {
    	if (*pattern == '\0')
    	{
    		return *source == '\0';
    	}
    	if (*(pattern+1)=='*')
    	{
    		if (*source != '\0' && (*pattern == *source || *pattern == '.'))
    		{
    			return isMatch(source, pattern+2) || isMatch(source+1, pattern);
    		}
    		else
    		{
    			return isMatch(source, pattern+2);
    		}
    	}
    	else
    	{
    		if (*source != '\0' && (*pattern == *source || *pattern == '.'))
    		{
    			return isMatch(source+1, pattern+1);
    		}
    	}
    	return false;  
    }
};

/*
Implement regular expression matching with support for '.' and '*'. 
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 Subscribe to see which companies asked this question. Show Tags Dynamic Programming Backtracking String Show Similar Problems (H) Wildcard Matching
*/
