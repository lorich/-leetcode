// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
// 

#include<limits.h>
class Solution {
public:
    bool isSpace(const char c)
    {
    	if (c==' ' || c=='\r' || c=='\n' || c=='\b' || c=='\f' || c=='\t')
    		return true;
    	return false;
    }
    
    bool isDigit(const char c)
    {
    	if (c >= '0' && c <= '9')
    		return true;
    	return false;
    }
    
    int getSign(const char c)
    {
    	switch(c)
    	{
    		case '+':return 1;
    		case '-':return -1;
    		default:
    			return 0;
    	}
    }
    
    int atoi(const char *str) 
    {
    	long long total = 0;
    	long long sign = 1;
        while(isSpace((char)*str))str++;
        if (getSign((char)*str) != 0)
        {
        	sign = getSign((char)*str);
        	str++;
        }
        while(isDigit((char)*str))
        {
        	total = total*10 + (char)*str - '0';
        	if (-1*total < INT_MIN)
        	{
        		break;
        	}
        	str++;
        }
        total = sign * total;
        if (total > INT_MAX)
        {
        	return INT_MAX;
        }
        if (total < INT_MIN)
        {
        	return INT_MIN;
        }
        return (int)total;
    }
};

/*
Implement atoi to convert a string to an integer. Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases. Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. Update (2015-02-10): The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. spoilers alert... click to show requirements for atoi. Requirements for atoi: The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value. The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function. If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed. If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned. Subscribe to see which companies asked this question. Show Tags Math String Show Similar Problems (E) Reverse Integer (H) Valid Number
*/
