// 398. Random Pick Index
// https://leetcode.com/problems/random-pick-index/
// 

class Solution {
private:
    typedef pair<int, int> pp; // <value, index>
    vector<pp> mNums;

public:
    static bool comp(const pp& i, const pp& j) { return (i.first < j.first); }
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); ++i) {
            mNums.push_back(pp({nums[i], i}));
        }
        sort(mNums.begin(), mNums.end(), comp);
    }

    int pick(int target) {
        auto bounds = equal_range(mNums.begin(), mNums.end(), pp({target,0}), comp);	//bounds.first: itrBegin, bounds.second: itrEnd
        return (bounds.first+rand()%(bounds.second-bounds.first))->second;
    }
};

/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array. Note: The array size can be very large. Solution that uses too much extra space will not pass the judge. Example: 
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
 Subscribe to see which companies asked this question. Show Tags Reservoir Sampling Show Similar Problems (M) Linked List Random Node
*/
