// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
// 

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> vecRightSide;
        queue<TreeNode*> queLayer;
        if (root)
        {
        	queLayer.push(root);
        }
        while(!queLayer.empty())
        {
        	const TreeNode * rightmost = queLayer.back();
        	while(queLayer.front() != rightmost)
        	{
        		TreeNode * cur = queLayer.front();
        		if (cur->left)
        		{
        			queLayer.push(cur->left);
        		}
        		if (cur->right)
        		{
        			queLayer.push(cur->right);
        		}
        		queLayer.pop();
        	}
        	queLayer.pop();
        	if (rightmost->left)
        	{
        		queLayer.push(rightmost->left);
        	}
        	if (rightmost->right)
        	{
        		queLayer.push(rightmost->right);
        	}
        	vecRightSide.push_back(rightmost->val);
        }
        return vecRightSide;
    }
};


/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. For example: Given the following binary tree, 
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 You should return [1, 3, 4]. Credits: Special thanks to @amrsaqr for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Breadth-first Search Show Similar Problems (M) Populating Next Right Pointers in Each Node
*/
