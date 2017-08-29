#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
  public:
    void fp(vector<int> &arr, const int s, const int e, vector<vector<int>> &res)
    {
        if (s == e)
            res.push_back(arr);
        unordered_set<int> visit;
        for (int i = s; i < e; ++i)
        {
            if(visit.find(arr[i]) != visit.end()) continue;
            visit.insert(arr[i]);
            swap(arr[i], arr[s]);
            fp(arr, s + 1, e, res);
            swap(arr[i], arr[s]);
        }
    }
    vector<vector<int>> fp(vector<int> &input)
    {
        vector<vector<int>> res;
        fp(input, 0, input.size(), res);
        return res;
    }
};

int main()
{
    vector<int> input = {2, 1, 3, 2, 1, 3};
    Solution so;
    auto res = move(so.fp(input));
    cout << res.size() << endl;
    for (auto v : res)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}