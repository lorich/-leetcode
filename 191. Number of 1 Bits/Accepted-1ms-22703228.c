// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
// 

int hammingWeight(uint32_t n) {
    int iBits=0;
    while(n)
    {
        n &= n-1;
        iBits++;
    }
    return iBits;
}

/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight). For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3. Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Bit Manipulation Show Similar Problems (E) Reverse Bits (E) Power of Two (M) Counting Bits (E) Binary Watch (E) Hamming Distance
*/
