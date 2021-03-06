// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/
// 

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& vIn) {
		int iRes = 0;
		if (vIn.size() < 3)
		{
			return iRes;
		}
		int iNumEndWithPre = 0, iNumEndWithCur = 0;
		for (size_t i = 2; i < vIn.size(); ++i)
		{
			if (vIn[i] + vIn[i - 2] == (vIn[i - 1] << 1))
			{
				iNumEndWithCur = iNumEndWithPre + 1;
			}
			else
			{
				iNumEndWithCur = 0;
			}
			iRes += iNumEndWithCur;
			iNumEndWithPre = iNumEndWithCur;
		}
		return iRes;
	}
};

/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same. For example, these are arithmetic sequence: 1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9 The following sequence is not arithmetic. 1, 1, 2, 5, 7 A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N. A slice (P, Q) of array A is called arithmetic if the sequence: A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q. The function should return the number of arithmetic slices in the array A. Example: 
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 Subscribe to see which companies asked this question. Show Tags Dynamic Programming Math Show Similar Problems (H) Arithmetic Slices II - Subsequence
*/
