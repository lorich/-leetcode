// 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/
// 

int char2int(char c)
{
	return c-'A'+1;
}

int titleToNumber(char *s) 
{
	int res = 0, i = 0;
	while(s[i])
	{
		res = res * 26 + char2int(s[i]);
		i++;
	}
	return res;
}

/*
Related to question Excel Sheet Column Title Given a column title as appear in an Excel sheet, return its corresponding column number. For example:     A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Math Show Similar Problems (E) Excel Sheet Column Title
*/
