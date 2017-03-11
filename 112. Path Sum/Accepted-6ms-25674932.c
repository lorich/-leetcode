// 112. Path Sum
// https://leetcode.com/problems/path-sum/
// 

bool hasPathSum2Leaf(struct TreeNode *root, int sum) {
	if (NULL == root->left && NULL == root->right)
	{
		return root->val == sum;
	}
	else if(NULL == root->left)
	{
		return hasPathSum2Leaf(root->right, sum-root->val);
	}
	else if(NULL == root->right)
	{
		return hasPathSum2Leaf(root->left, sum-root->val);
	}
	else
	{
		return hasPathSum2Leaf(root->right, sum-root->val) || hasPathSum2Leaf(root->left, sum-root->val);
	}
}
 
bool hasPathSum(struct TreeNode *root, int sum) {
    if(NULL == root){
    	return false;
    }
    return hasPathSum2Leaf(root, sum);
}

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. For example: Given the below binary tree and sum = 22, 
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (M) Path Sum II (H) Binary Tree Maximum Path Sum (M) Sum Root to Leaf Numbers (E) Path Sum III
*/
