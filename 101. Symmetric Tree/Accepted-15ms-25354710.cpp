// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
// 

class Solution {
public:
	bool isSymmetricBet(TreeNode *left, TreeNode *right)
	{
		if (NULL == left && NULL == right)
		{
			return true;
		}
		else if (NULL == left || NULL == right)
		{
			return false;
		}
		else if(left->val != right->val)
		{
			return false;
		}
		else
		{
			return isSymmetricBet(left->left, right->right) && isSymmetricBet(left->right, right->left);
		}
	}
    bool isSymmetric(TreeNode *root) 
    {
    	if (NULL == root)
	    {
	    	return true;
	    }   
	    return isSymmetricBet(root->left, root->right);
    }
};

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
    1
   / \
  2   2
 / \ / \
3  4 4  3
 But the following [1,2,2,null,3,null,3] is not: 
    1
   / \
  2   2
   \   \
   3    3
 Note: Bonus points if you could solve it both recursively and iteratively. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Breadth-first Search
*/
