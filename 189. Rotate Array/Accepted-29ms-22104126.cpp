// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// 


class Solution {
public:
	void swap(int &a, int &b)
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}
    void rotate(int nums[], int n, int k) 
    {
        if(n <= 0 || k <= 0)return;
        k = k % n;
        if(k)
        {
            int start = 0;
            int pos = start, toRotate = nums[pos];
            for (int i = 0; i < n; ++i)
            {
                swap(nums[(pos + k) % n], toRotate);
                pos = (pos + k) % n;
                if (pos == start && i < n)
                {
                    start++;
                    pos = start, toRotate = nums[pos];
                }
            }
        }
    }
};

/*
Rotate an array of n elements to the right by k steps. For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. Note: Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. [show hint] Hint: Could you do it in-place with O(1) extra space? Related problem: Reverse Words in a String II Credits: Special thanks to @Freezen for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Array Show Similar Problems (M) Rotate List (M) Reverse Words in a String II
*/
