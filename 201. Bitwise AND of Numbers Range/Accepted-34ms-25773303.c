// 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// 

int rangeBitwiseAnd(int m, int n) 
{
	int offset = 0;
	while( m && n && m != n)
	{
		offset++;
		m >>= 1;
		n >>= 1;
	}   
	return m&&n ? m<<offset : 0;
}

/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive. For example, given the range [5, 7], you should return 4. Credits: Special thanks to @amrsaqr for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation
*/
