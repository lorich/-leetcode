// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// 

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)>0?(a):(-(a)))
int checkDepth(struct TreeNode* root) 
{
	if (NULL == root)
	{
		return 0;
	}
	int leftDepth = checkDepth(root->left);
	if (-1 == leftDepth)
	{
		return leftDepth;
	}
	int rightDepth = checkDepth(root->right);
	if (-1 == rightDepth)
	{
		return rightDepth;
	}
	if (ABS(leftDepth-rightDepth)>1)
	{
		return -1;
	}
	return MAX(leftDepth, rightDepth)+1;
}

bool isBalanced(struct TreeNode* root) 
{
	if (-1 == checkDepth(root))
	{
		return false;
	}
	return true;
}

/*
Given a binary tree, determine if it is height-balanced. For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) Maximum Depth of Binary Tree
*/
