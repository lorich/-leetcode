// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// 

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> staPath;
        vector<int> vecPreOrder;
        if (root)
        {
        	staPath.push(root);
        }
        while(!staPath.empty())
        {
        	TreeNode * curNode = staPath.top();
        	staPath.pop();
        	vecPreOrder.push_back(curNode->val);
        	if (curNode->right)
        	{
        		staPath.push(curNode->right);
        	}
        	if (curNode->left)
        	{
        		staPath.push(curNode->left);
        	}
        }
        return vecPreOrder;
    }
};

/*
Given a binary tree, return the preorder traversal of its nodes' values. For example: Given binary tree {1,#,2,3}, 
   1
    \
     2
    /
   3
 return [1,2,3]. Note: Recursive solution is trivial, could you do it iteratively? Subscribe to see which companies asked this question. Show Tags Tree Stack Show Similar Problems (M) Binary Tree Inorder Traversal (M) Verify Preorder Sequence in Binary Search Tree
*/
