// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> sta;
        vector<int> vecRes;
        if (root)
        {
        	sta.push(root);
        }
        while(!sta.empty())
        {
        	TreeNode* curNode = sta.top();
        	while(curNode)
        	{
        		sta.push(curNode->left);
        		curNode = curNode->left;
        	}
        	sta.pop();
        	if (!sta.empty())
        	{
        		curNode = sta.top();
	        	sta.pop();
	        	vecRes.push_back(curNode->val);
	        	sta.push(curNode->right);
        	}
        }
        return vecRes;
    }
};

/*
Given a binary tree, return the inorder traversal of its nodes' values. For example: Given binary tree [1,null,2,3], 
   1
    \
     2
    /
   3
 return [1,3,2]. Note: Recursive solution is trivial, could you do it iteratively? Subscribe to see which companies asked this question. Show Tags Tree Hash Table Stack Show Similar Problems (M) Validate Binary Search Tree (M) Binary Tree Preorder Traversal (H) Binary Tree Postorder Traversal (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST (H) Closest Binary Search Tree Value II (M) Inorder Successor in BST
*/
