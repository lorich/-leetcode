// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/
// 

uint32_t reverseBits(uint32_t n) 
{
	uint32_t ret = 0;
	int bits = 32;
	while(bits--)
	{
		ret = (ret << 1) | (n & 0x1);
		n = n >> 1;
	}    
	return ret;
}

/*
Reverse bits of a given 32 bits unsigned integer. For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000). Follow up: If this function is called many times, how would you optimize it? Related problem: Reverse Integer Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (E) Number of 1 Bits
*/