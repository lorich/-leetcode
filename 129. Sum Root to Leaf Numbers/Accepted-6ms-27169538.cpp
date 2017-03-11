// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// 

class Solution {
public:
	int m_sum;
	void preOrderTraverse(TreeNode* root, int iSum)
	{
		if (root)
		{
			iSum = iSum*10 + root->val;
			if (!root->left && !root->right)
			{
				m_sum += iSum;
				return;
			}
			if(root->left)preOrderTraverse(root->left, iSum);
			if(root->right)preOrderTraverse(root->right, iSum);
		}
	}
    int sumNumbers(TreeNode* root) 
    {
    	m_sum = 0;
    	preOrderTraverse(root, 0);
    	return m_sum;
    }
};

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of all root-to-leaf numbers. For example, 
    1
   / \
  2   3
 The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number 13. Return the sum = 12 + 13 = 25. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) Path Sum (H) Binary Tree Maximum Path Sum
*/
