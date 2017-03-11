// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// 

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int> > vecRes;
    	vector<TreeNode*> vecBD;
    	int nCurIndex = -1;
    	if (root)
    	{
    		vecBD.push_back(root);
    	}
    	while(nCurIndex < (int)vecBD.size()-1)
    	{
    		vecBD.push_back(NULL);
    		while(NULL != vecBD[++nCurIndex])
    		{
    			TreeNode * curNode = vecBD[nCurIndex];
    			if (curNode->right)
    			{
    				vecBD.push_back(curNode->right);
    			}
    			if (curNode->left)
    			{
    				vecBD.push_back(curNode->left);
    			}
    		}
    	}
    	while(nCurIndex >= 0)
    	{
    		if (NULL == vecBD[nCurIndex])
    		{
    			nCurIndex--;
    		}
    		vector<int> vecLev;
    		while(nCurIndex >= 0 && NULL != vecBD[nCurIndex])
    		{
    			vecLev.push_back(vecBD[nCurIndex]->val);
    			nCurIndex--;
    		}
    		vecRes.push_back(vecLev);
    	}
    	return vecRes;
    }
};

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root). For example: Given binary tree [3,9,20,null,null,15,7], 
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as: 
[
  [15,7],
  [9,20],
  [3]
]
 Subscribe to see which companies asked this question. Show Tags Tree Breadth-first Search Show Similar Problems (M) Binary Tree Level Order Traversal
*/
