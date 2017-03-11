// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 

#include <memory.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t nIndex[260] = {0};
        size_t maxLen = 0;
        size_t curLen = 0;
        for(size_t i = 0; i < s.size();)
        {
            char c = s[i];
            if(nIndex[c])
            {
                i = nIndex[c];
                curLen = 0;
                memset(nIndex, 0, 260*sizeof(size_t));
            }
            else
            {
                curLen ++;
                nIndex[c]=i+1;
                i++;
                if(curLen > maxLen)
                {
                    maxLen = curLen;
                }
            }
        }
        return maxLen;
    }
};

/*
Given a string, find the length of the longest substring without repeating characters. Examples: Given "abcabcbb", the answer is "abc", which the length is 3. Given "bbbbb", the answer is "b", with the length of 1. Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring. Subscribe to see which companies asked this question. Show Tags Hash Table Two Pointers String Show Similar Problems (H) Longest Substring with At Most Two Distinct Characters
*/
