// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// 

class Solution {
public:
	int minDepth2Leaf(TreeNode* root)
	{
		if (NULL == root->left && NULL == root->right)
		{
			return 1;
		}
		else if(NULL == root->left)
		{
			return minDepth2Leaf(root->right)+1;
		}
		else if(NULL == root->right)
		{
			return minDepth2Leaf(root->left)+1;
		}
		else
		{
			int minLeft = minDepth2Leaf(root->left)+1;
    		int minRight = minDepth2Leaf(root->right)+1;
    		return minLeft < minRight ? minLeft : minRight;
		}
	}
    int minDepth(TreeNode *root) {
    	if (NULL == root)
    	{
    		return 0;
    	}
    	return minDepth2Leaf(root);
    }
};

/*
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Breadth-first Search Show Similar Problems (M) Binary Tree Level Order Traversal (E) Maximum Depth of Binary Tree
*/
