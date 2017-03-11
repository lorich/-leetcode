// 395. Longest Substring with At Least K Repeating Characters
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// 

class Solution {
public:
    void explodeStr(const string& s, int arrCounter[26], const int k, vector<string>& vecStr)
    {
        string strSub;
        int i=0, len=s.size();
        while(i < len)
        {
            while(arrCounter[s[i]-'a'] < k && i<len)i++;
            while(arrCounter[s[i]-'a'] >=k && i<len)
            {
                strSub.push_back(s[i]);
                i++;
            }
            if(!strSub.empty())
            {
                vecStr.push_back(strSub);
                strSub.clear();
            }
        }
    }
    int longestSubstring(string s, int k) {
        int arrCounter[26]={0};
        for (auto c:s)
        {
            arrCounter[c-'a']++;
        }
        int iLessCounter=0, iGreaterE=0;
        for (int i = 0; i < 26; ++i)
        {
            if (arrCounter[i] > 0)
            {
                arrCounter[i] < k ? iLessCounter++ : iGreaterE++;
            }
        }
        if (0 == iGreaterE)
        {
            return 0;
        }
        if (0 == iLessCounter)
        {
            return s.size();
        }
        vector<string> vecStr;
        this->explodeStr(s, arrCounter, k, vecStr);
        int iLongestSoFar=0;
        for (string strSub:vecStr)
        {
            if (strSub.size() <= iLongestSoFar)
            {
                continue;
            }
            int iCur = this->longestSubstring(strSub, k);
            if (iCur > iLongestSoFar)
            {
                iLongestSoFar = iCur;
            }
        }
        return iLongestSoFar;
    }
};

/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times. Example 1: 
Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
 Example 2: 
Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 Subscribe to see which companies asked this question.
*/
