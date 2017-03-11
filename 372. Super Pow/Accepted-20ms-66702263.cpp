// 372. Super Pow
// https://leetcode.com/problems/super-pow/
// 

class Solution {
public:
    const static int base=1337;
    int mod(int a, int p)
    {
        int r=1;
        for (int i = 0; i < p; ++i)
        {
            r=(r*a)%base;
        }
        return r;
    }
    int superPow(int a, vector<int>& b) 
    {
        if(b.empty()) return 1;
        a %= base;
        int lastbit=b.back();
        b.pop_back();
        return mod(superPow(a, b), 10)*mod(a, lastbit)%base;
    }
};

/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array. Example1: 
a = 2
b = [3]

Result: 8
 Example2: 
a = 2
b = [1,0]

Result: 1024
 Credits: Special thanks to @Stomach_ache for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Math Show Similar Problems (M) Pow(x, n)
*/
