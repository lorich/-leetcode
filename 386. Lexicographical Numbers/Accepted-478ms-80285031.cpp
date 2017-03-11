// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/
// 


class Solution {
public:
    void findNumPrefixInLexOrder(int begin, vector<int>& vecRes, const int num)
    {
        begin *= 10;
        for (int i = 0; i < 10 && begin+i <= num; ++i)
        {
            vecRes.push_back(begin+i);
            findNumPrefixInLexOrder(begin+i, vecRes, num);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> vecRes;
        for (int i = 1; i < 10 && i <= n; ++i)
        {
            vecRes.push_back(i);
            findNumPrefixInLexOrder(i, vecRes, n);
        }
        return vecRes;
    }
};


/*
Given an integer n, return 1 - n in lexicographical order. For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. Subscribe to see which companies asked this question.
*/
