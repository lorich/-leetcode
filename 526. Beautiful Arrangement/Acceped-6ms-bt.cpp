#include <vector>
using namespace std;

class Solution
{
  public:
    int cnt(vector<int> &arr, const int n)
    {
        
        if (n <= 0)
            return 1;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] % n == 0 or n % arr[i] == 0)
            {
                swap(arr[i], arr[n - 1]);
                res += cnt(arr, n - 1);
                swap(arr[i], arr[n - 1]);
            }
        }
        return res;
    }
    int countArrangement(int N)
    {
        vector<int> arr;
        for (int i = 0; i < N; ++i)
            arr.push_back(i + 1);
        return cnt(arr, N);
    }
};

int main()
{
    return 0;
}