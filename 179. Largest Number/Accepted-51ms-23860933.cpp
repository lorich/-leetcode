// 179. Largest Number
// https://leetcode.com/problems/largest-number/
// 

class Solution {
public:
	static bool less(const int a, const int b)
	{
		stringstream ssAb, ssBa;
		ssAb << a << b;
		ssBa << b << a;
		return ssAb.str() > ssBa.str();
	}
    string largestNumber(vector<int> &num) 
    {
        sort(num.begin(), num.end(), less);
        if (!num.empty() && 0 == num[0])
        {
        	return "0";
        }
        stringstream ssResult;
        for (size_t i = 0; i < num.size(); ++i)
        {
        	ssResult << num[i];
        }
        return ssResult.str();
    }
};

/*
Given a list of non negative integers, arrange them such that they form the largest number. For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330. Note: The result may be very large, so you need to return a string instead of an integer. Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Sort
*/
