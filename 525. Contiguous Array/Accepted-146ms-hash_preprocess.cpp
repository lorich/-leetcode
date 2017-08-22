
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        for (auto &i : nums)
        {
            if (0 == i)
                i = -1;
        }
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (sumToIndex.find(sum) != sumToIndex.end())
            {
                res = max(res, i - sumToIndex[sum]);
            }
            else
            {
                sumToIndex[sum] = i;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}