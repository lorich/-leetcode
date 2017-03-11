// 397. Integer Replacement
// https://leetcode.com/problems/integer-replacement/
// 

class Solution {
public:
    int integerReplacement(int n) {
        //assert(n>0);
        if (1 == n) return 0;
        if (INT_MAX == n) return 32;
        if(n&1)
        {
            int a=this->integerReplacement(n-1);
            int b=this->integerReplacement(n+1);
            return min(a,b)+1;
        }
        else
        {
            return this->integerReplacement(n/2)+1;
        }
    }
};

/*
Given a positive integer n and you can do operations as follow: If n is even, replace n with n/2. If n is odd, you can replace n with either n + 1 or n - 1. What is the minimum number of replacements needed for n to become 1? Example 1: 
Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
 Example 2: 
Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
 Subscribe to see which companies asked this question. Show Tags Math Bit Manipulation
*/
