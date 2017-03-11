// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// 

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)>0?(a):(-(a)))
int calDepth(struct TreeNode* root) 
{
	if (NULL == root)
	{
		return 0;
	}
	return MAX(calDepth(root->left), calDepth(root->right))+1;
}

bool isBalanced(struct TreeNode* root) 
{
	if (NULL == root)
	{
		return true;
	}
	int depthLeft=calDepth(root->left);
	int depthRight=calDepth(root->right);
	if (ABS(depthLeft-depthRight) > 1)
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}

/*
Given a binary tree, determine if it is height-balanced. For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) Maximum Depth of Binary Tree
*/
