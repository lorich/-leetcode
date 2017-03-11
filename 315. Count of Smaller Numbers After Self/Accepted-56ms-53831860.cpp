// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// 

class FenwickTree {
	vector<int> sum_array;
	int n;
	inline int lowbit(int x) {
		return x & -x;
	}
 
public:
	FenwickTree(int n) :n(n), sum_array(n + 1, 0) {}
 
	void add(int x, int val) {
		while (x <= n) {
			sum_array[x] += val;
			x += lowbit(x);
		}
	}
	
	int sum(int x) {
		int res = 0;
		while (x > 0) {
			res += sum_array[x];
			x -= lowbit(x);
		}
		return res;
	}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& vecNums) {
    	vector<int> vecTempNums = vecNums;
    	sort(vecTempNums.begin(), vecTempNums.end());
        unordered_map<int, int> mapSortSeq;
        for (int i = 0; i < vecTempNums.size(); ++i)
        {
        	mapSortSeq[vecTempNums[i]] = i+1;
        }

        FenwickTree oFenWickTree(vecNums.size());
        vector<int> vecRes(vecNums.size(), 0);
        for (int i = vecNums.size()-1; i >= 0; --i)
        {
        	vecRes[i] = oFenWickTree.sum(mapSortSeq[vecNums[i]]-1);
        	oFenWickTree.add(mapSortSeq[vecNums[i]], 1);
        }
        return vecRes;
    }
};

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]. Example: 
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
 Return the array [2, 1, 1, 0]. Subscribe to see which companies asked this question. Show Tags Divide and Conquer Binary Indexed Tree Segment Tree Binary Search Tree Show Similar Problems (H) Count of Range Sum (M) Queue Reconstruction by Height (H) Reverse Pairs
*/
