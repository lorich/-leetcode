//
// Created by grep on 19/05/07.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;
        int minPre = nums[0], maxPre = nums[0], maxRes = nums[0], minCur, maxCur;
        for (int i = 1; i < nums.size(); ++i) {
            maxCur = max(max(maxPre * nums[i], nums[i]), minPre * nums[i]);
            minCur = min(min(maxPre * nums[i], nums[i]), minPre * nums[i]);
            if (maxCur > maxRes) maxRes = maxCur;
            minPre = minCur;
            maxPre = maxCur;
        }
        return maxRes;
    }
};