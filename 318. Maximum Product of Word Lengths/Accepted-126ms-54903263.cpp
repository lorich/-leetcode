// 318. Maximum Product of Word Lengths
// https://leetcode.com/problems/maximum-product-of-word-lengths/
// 

class Solution {
public:
	int str2int(const string& strIn)
	{
		int iRes = 0;
		for (size_t i = 0; i < strIn.size(); ++i)
		{
			iRes |= 1 << (strIn[i] - 'a');
		}
		return iRes;
	}
    int maxProduct(vector<string>& vecWords) 
    {
    	size_t nWordsSize = vecWords.size();
    	if (nWordsSize <= 1)return 0;
    	vector<int> vecWord2int(nWordsSize, 0);
    	for (size_t i = 0; i < nWordsSize; ++i)
    	{
    		vecWord2int[i] = this->str2int(vecWords[i]);
    	}
    	int iRes = 0;
    	for (size_t i = 0; i < nWordsSize; ++i)
    	{
    		for (size_t j = i+1; j < nWordsSize; ++j)
    		{
    			if (0 == (vecWord2int[i] & vecWord2int[j]))
    			{
    				iRes = max(iRes, (int)(vecWords[i].size()*vecWords[j].size()));
    			}
    		}
    	}
    	return iRes;
    }
};

/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0. Example 1: Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"] Return 16 The two words can be "abcw", "xtfn". Example 2: Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"] Return 4 The two words can be "ab", "cd". Example 3: Given ["a", "aa", "aaa", "aaaa"] Return 0 No such pair of words. Credits: Special thanks to @dietpepsi for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation
*/
