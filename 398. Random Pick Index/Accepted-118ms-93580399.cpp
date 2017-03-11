// 398. Random Pick Index
// https://leetcode.com/problems/random-pick-index/
// 


class Solution {
private:
	vector<int> m_vecNums;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        m_vecNums = nums;
    }
    
    int pick(int target) {
    	int iRes = -1, iCounter=1;
    	for (int i = 0; i < m_vecNums.size(); ++i)
    	{
    		if (m_vecNums[i] != target) continue;
    		if (!(rand()%iCounter++)) iRes=i;
    	}
    	return iRes;
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
