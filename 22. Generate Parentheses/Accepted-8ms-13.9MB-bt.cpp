#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int calString(const string &generated)
    {
        int res = 0;
        for (auto c : generated)
        {
            if (c == '(')
                res++;
            else
                res--;
        }
        return res;
    }
    void bt(int l, int r, string &generated, vector<string> &result)
    {
        if (l < 0 or r < 0 or calString(generated) < 0)
            return;
        if (0 == l and 0 == r)
        {
            if (calString(generated) == 0)
                result.push_back(generated);
            return;
        }
        generated.push_back('(');
        bt(l - 1, r, generated, result);
        generated.pop_back();
        generated.push_back(')');
        bt(l, r - 1, generated, result);
        generated.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string generated;
        bt(n, n, generated, result);
        return result;
    }
};

int main()
{
    Solution so;
    vector<string> vecRes = so.generateParenthesis(0);
    cout << vecRes.size() << endl;
    for (auto s : vecRes)
    {
        cout << s << endl;
    }
    return 0;
}