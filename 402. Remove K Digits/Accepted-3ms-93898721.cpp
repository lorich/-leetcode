// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/
// 

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (num.empty() || num.size() == k)
		{
			return "0";
		}
		string strRes;
		for (size_t i = 0; i < num.size();)
		{
			const char c = num[i];
			if (strRes.empty() && '0' == c)
			{
				i++;
				continue;
			}
			if (strRes.empty() || 0 == k || c >= strRes.back())
			{
				strRes.push_back(c);
				i++;
			}
			else
			{
				strRes.pop_back();
				k--;
			}
		}
		while (k-- && ! strRes.empty()) strRes.pop_back();
		if(strRes.empty()) strRes="0";
		return strRes;
	}
};

/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible. Note: The length of num is less than 10002 and will be ≥ k. The given num does not contain any leading zero. Example 1: 
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 Example 2: 
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 Example 3: 
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 Subscribe to see which companies asked this question. Show Tags Stack Greedy Show Similar Problems (H) Create Maximum Number
*/
