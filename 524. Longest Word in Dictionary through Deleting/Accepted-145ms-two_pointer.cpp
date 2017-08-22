#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string findLongestWord(const string& s, const vector<string>& d)
    {
        string ans;
        for (size_t i = 0; i < d.size(); i++)
        {
            size_t pi = 0, pj = 0;
            for (; pi < s.size() && pj < d[i].size(); pi++)
            {
                pj += s[pi] == d[i][pj];
            }
            if (pj == d[i].size() && (ans.size() < d[i].size() || (ans.size() == d[i].size() && ans > d[i])))
                ans = d[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}