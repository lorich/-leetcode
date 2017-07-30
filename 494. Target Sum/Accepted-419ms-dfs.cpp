#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findTargetSumWaysWithSize(const vector<int>& nums, const int size, const int s){
            if(size < 1) return 0;
            if(size == 1) return (nums[0] == s) + (-nums[0] == s);
            return findTargetSumWaysWithSize(nums, size-1, s+nums[size-1]) + findTargetSumWaysWithSize(nums, size-1, s-nums[size-1]);
        }
        int findTargetSumWays(const vector<int>& nums, const int S) {
            return findTargetSumWaysWithSize(nums, nums.size(), S);        
        }
};

int main(int argc, char const *argv[])
{
    Solution so;
    cout << so.findTargetSumWays({0,0,0,0,0,0,0,0,1}, 1) << endl;
    return 0;
}
