// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// 

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.empty())
    	{
    		return 0;
    	}
    	int i = 0, j=height.size()-1;
    	int maxA = 0, maxI = i, maxJ = j, curArea = 0;
    	while(i < j)
    	{
    		curArea = (j-i)*min(height[i], height[j]);
    		if (curArea > maxA)
    		{
    			maxA = curArea;
    			maxI = i;
    			maxJ = j;
    		}
    		height[i] < height[j] ? i++ : j--;
    	}
    	return maxA;
    }
};

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. Note: You may not slant the container and n is at least 2. Subscribe to see which companies asked this question. Show Tags Array Two Pointers Show Similar Problems (H) Trapping Rain Water
*/
