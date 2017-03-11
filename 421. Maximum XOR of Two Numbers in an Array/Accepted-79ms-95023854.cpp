// 421. Maximum XOR of Two Numbers in an Array
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// 

class Solution
{
public:
	class Node
	{
	public:
		Node* next[2];
		Node() {next[0] = NULL, next[1] = NULL;};
	};

	Node * buildTrie(const vector<int>& nums)
	{
		Node* root = new Node();
		for (auto num : nums)
		{
			Node* cur = root;
			for (int i = 30; i >= 0; --i)
			{
				int index = (num >> i) & 0x1;
				if (cur->next[index] == NULL)
					cur->next[index] = new Node();
				cur = cur->next[index];
			}
		}
		return root;
	}

	int calMaxXOR(const int num, Node* root)
	{
		int res = 0;
		for (int i = 30; i >= 0; --i)
		{
			res <<= 1;
			int indexNot = 1 - (num >> i) & 0x1;
			if (root->next[indexNot])
			{
				res |= 0x1;
				root = root->next[indexNot];
			}
			else
			{
				root = root->next[1 - indexNot];
			}
		}
		return res;
	}

	int findMaximumXOR(const vector<int> & nums)
	{
		int res = 0;
		Node * root = buildTrie(nums);
		for ( auto n : nums)
		{
			res = max(res, calMaxXOR(n, root));
		}
		return res;
	}
};

/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231. Find the maximum result of ai XOR aj, where 0 ≤ i, j < n. Could you do this in O(n) runtime? Example: 
Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
 Subscribe to see which companies asked this question. Show Tags Bit Manipulation Trie
*/
