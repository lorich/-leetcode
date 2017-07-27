#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
    public:
        int sortCount(vector<int>::iterator begin, vector<int>::iterator end) {
            if(end - begin <= 1) return 0;
            auto mid = begin + (end - begin)/2;
            int count = sortCount(begin, mid) + sortCount(mid, end);
            for(auto i=begin, j=mid; i < mid; ++i)
            {
                while (j < end and *i > (int64_t)*j<<1)
                    ++j;
                count += j-mid;
            }
            inplace_merge(begin, mid, end);
            return count;
        }

        int reversePairs(vector<int>& nums) {
            return sortCount(nums.begin(), nums.end());
        }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> in({1,3,2,1,2147483647});
    cout << so.reversePairs(in) << endl;
    return 0;
}
