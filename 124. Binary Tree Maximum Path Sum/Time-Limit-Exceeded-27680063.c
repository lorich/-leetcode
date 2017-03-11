// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// 

#define MAX(a,b) ((a)>(b)?(a):(b))
int maxPath(struct TreeNode* root) 
{
	if (NULL == root)
	{
		return 0;
	}
	else if (NULL == root->left && NULL == root->right)
	{
		return root->val;
	}
	else if(NULL == root->left)
	{
		return root->val + maxPath(root->right);
	}
	else if (NULL == root->right)
	{
		return root->val + maxPath(root->left);
	}
	else
	{
		return root->val + MAX(maxPath(root->right), maxPath(root->left));
	}
}
int maxPathSum(struct TreeNode* root) 
{
	if (NULL == root)
	{
		return 0;
	}
	else if (NULL == root->left && NULL == root->right)
	{
		return root->val;
	}
	else if(NULL == root->left)
	{
		return MAX(maxPath(root), maxPathSum(root->right));
	}
	else if (NULL == root->right)
	{
		return MAX(maxPath(root), maxPathSum(root->left));
	}
	else
	{
		return MAX(MAX(maxPathSum(root->right), maxPathSum(root->left)),
			   root->val + maxPath(root->left) + maxPath(root->right));
	}
}

/*
Given a binary tree, find the maximum path sum. For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root. For example: Given the below binary tree, 
       1
      / \
     2   3
 Return 6. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) Path Sum (M) Sum Root to Leaf Numbers
*/
