// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/
// 

int trailingZeroes(int n) {
    int ret = 0;
    while(n)
    {
        ret += n/5;
        n /= 5;
    }
    return ret;
}

/*
Given an integer n, return the number of trailing zeroes in n!. Note: Your solution should be in logarithmic time complexity. Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Math Show Similar Problems (H) Number of Digit One
*/
