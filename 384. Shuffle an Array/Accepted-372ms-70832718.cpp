// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/
// 

class Solution {
private:
    vector<int> m_vecNums;

public:
    Solution(const vector<int>& nums) {
        m_vecNums = nums;
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_vecNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto vecTempNum = m_vecNums;
        auto size=vecTempNum.size();
        if (size < 2)
        {
            return vecTempNum;
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                auto randIndex = rand()%(size-i);
                if (0 == randIndex) continue;
                //swap i and i+randIndex
                [](int& a, int& b) -> void{int c=a;a=b;b=c;}(vecTempNum[i], vecTempNum[i+randIndex]);
            }
        }
        return vecTempNum;
    }
};

/*
Shuffle a set of numbers without duplicates. Example: 
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
 Subscribe to see which companies asked this question.
*/
