// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/
// 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool arrVisit[256]={0};
        uint32_t arrLecNums[256]={0};
        for(auto c:s) arrLecNums[c]++;
        string strRes("0");
    	for(auto c:s)
    	{
    		arrLecNums[c]--;
    		if(arrVisit[c]) continue;
    		while(c < strRes.back() && arrLecNums[strRes.back()])
    		{
    			arrVisit[strRes.back()]=false;
    			strRes.pop_back();
    		}
    		strRes.push_back(c);
    		arrVisit[c]=true;
    	}
    	return strRes.substr(1);
    }
};

/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results. Example: Given "bcabc" Return "abc" Given "cbacdcbc" Return "acdb" Credits: Special thanks to @dietpepsi for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Stack Greedy
*/
