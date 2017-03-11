// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/
// 

const static int FOUR_TEN = 1048576;
const static int FOUR_NINE = 262144;

class Solution {
public:
	int DNAMapping(char c)
	{
		switch(c)
		{
			case 'A': return 0;
			case 'C': return 1;
			case 'G': return 2;
			case 'T': return 3;
			default:
				return -1;

		}
	}
	int DNAHash(string s)
	{
		int iHash = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			iHash = iHash * 4 + DNAMapping(s[i]); 
		}
		return iHash;
	}
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vecRes;
        char cMap[FOUR_TEN] = {0};	//0:未出现，1:出现一次，2:出现两次及以上
        int iSize = s.size();
        if (iSize > 10)
        {
        	int iCurHash = DNAHash(s.substr(0, 10));
        	cMap[iCurHash] = 1;
        	for (int i = 10; i < iSize; ++i)
        	{
        		iCurHash = (iCurHash % FOUR_NINE) * 4 + DNAMapping(s[i]);
        		if (1 == cMap[iCurHash])
        		{
        			vecRes.push_back(s.substr(i-9, 10));
        			cMap[iCurHash] = 2;
        		}
        		else if(0 == cMap[iCurHash])
        		{
        			cMap[iCurHash] = 1;
        		}
        	}
        }
        return vecRes;
    }
};

/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA. Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. For example, 
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 Subscribe to see which companies asked this question. Show Tags Hash Table Bit Manipulation
*/
