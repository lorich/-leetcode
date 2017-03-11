// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
// 

struct TreeNode* invertTree(struct TreeNode* root) 
{
	if (root)
	{
		//swap left & right
		struct TreeNode * tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
	}    
	return root;
}

/*
Invert a binary tree.      4
   /   \
  2     7
 / \   / \
1   3 6   9 to      4
   /   \
  7     2
 / \   / \
9   6 3   1 Trivia: This problem was inspired by this original tweet by Max Howell: Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off. Subscribe to see which companies asked this question. Show Tags Tree
*/
