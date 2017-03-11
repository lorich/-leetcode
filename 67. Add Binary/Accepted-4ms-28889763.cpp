// 67. Add Binary
// https://leetcode.com/problems/add-binary/
// 

class Solution {
public:
    string addBinary(string a, string b) 
    {
    	string strRes;   
    	int iLenA = a.size()-1, iLenB = b.size()-1;
    	int iCarry = 0, iSum = 0;
    	while(iLenA >=0 || iLenB >= 0 || iCarry > 0)
    	{
    		iSum = iCarry;
    		if (iLenA >= 0)
    		{
    			iSum += a[iLenA]-'0';
    		}
    		if (iLenB >= 0)
    		{
    			iSum += b[iLenB]-'0';
    		}
    		strRes.insert(strRes.begin(), (iSum%2)+'0');
    		iCarry = iSum/2;
    		iLenA--, iLenB--;
    	}
    	return strRes;
    }
};

/*
Given two binary strings, return their sum (also a binary string). For example, a = "11" b = "1" Return "100". Subscribe to see which companies asked this question. Show Tags Math String Show Similar Problems (M) Add Two Numbers (M) Multiply Strings (E) Plus One
*/
