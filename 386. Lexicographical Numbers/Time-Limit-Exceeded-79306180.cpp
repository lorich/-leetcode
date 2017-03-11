// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/
// 

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> vecRes;
        for (int i = 1; i <= n; ++i)
        {
            vecRes.push_back(i);
        }
        auto lexicalBefore = [](int i, int j) {
            stringstream ss;
            string a, b;
            ss << i;
            ss >> a;
            ss.str("");
            ss.clear();
            ss << j;
            ss >> b;
            auto itra=a.begin(), itrb=b.begin();
            while(itra != a.end() && itrb != b.end() && *itra == *itrb)
            {
                itra++;
                itrb++;
            }
            return (itra != a.end() && itrb != b.end()) ? *itra < *itrb : itra == a.end();
        };
        sort(vecRes.begin(), vecRes.end(), lexicalBefore);
        return vecRes;
    }
};

/*
Given an integer n, return 1 - n in lexicographical order. For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. Subscribe to see which companies asked this question.
*/
