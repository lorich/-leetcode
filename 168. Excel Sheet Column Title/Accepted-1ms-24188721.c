// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/
// 

#define MAX_SIZE 1000

char int2char(int key)
{
	return key + 'A' - 1;
}

void swap(char * a, char * b)
{
	char temp;
	temp = *a;
	*a=*b;
	*b=temp;
}

char *convertToTitle(int n) 
{
	char* res = (char *)malloc(MAX_SIZE);
	memset(res, 0, MAX_SIZE);
	int bitCounter = 0;
	while(n)
	{
		int cur = n % 26;
		if (cur)
		{
			res[bitCounter++] = int2char(cur);
		}
		else
		{
			res[bitCounter++] = 'Z';
			n -= 26;
		}
		n /= 26;
	}
	int i;
	for (i = 0; i < bitCounter/2; ++i)
	{
		swap(&res[i], &res[bitCounter-i-1]);
	}
	return res;
}

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet. For example: 
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB Credits: Special thanks to @ifanchu for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Math Show Similar Problems (E) Excel Sheet Column Number
*/
