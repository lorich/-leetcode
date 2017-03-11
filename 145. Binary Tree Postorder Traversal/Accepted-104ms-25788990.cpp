// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) 
    {
    	vector<int> vecPostOrder;
    	stack<TreeNode*>  staRun;
    	if (root)
	    {
	    	staRun.push(root);
	    }   
	    TreeNode* preNode = NULL;
	    while(!staRun.empty())
	    {
	    	TreeNode* curNode = staRun.top();
	    	if ( (NULL == curNode->left && NULL == curNode->right)
	    	 	|| (NULL != preNode && (preNode == curNode->right || preNode == curNode->left)) )
	    	{
	    		vecPostOrder.push_back(curNode->val);
	    		staRun.pop();
	    		preNode = curNode;
	    	}
	    	else
	    	{
	    		if (NULL != curNode->right)
		    	{
		    		staRun.push(curNode->right);
		    	}
		    	if (NULL != curNode->left)
		    	{
		    		staRun.push(curNode->left);
		    	}
	    	}
	    }
	    return vecPostOrder;
    }
};

/*
Given a binary tree, return the postorder traversal of its nodes' values. For example: Given binary tree {1,#,2,3}, 
   1
    \
     2
    /
   3
 return [3,2,1]. Note: Recursive solution is trivial, could you do it iteratively? Subscribe to see which companies asked this question. Show Tags Tree Stack Show Similar Problems (M) Binary Tree Inorder Traversal
*/
