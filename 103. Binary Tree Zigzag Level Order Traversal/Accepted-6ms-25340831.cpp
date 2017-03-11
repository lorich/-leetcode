// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// 

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vecRes;
        stack<TreeNode*> staLevL2R;
        stack<TreeNode*> staLevR2L;
        if (root)
        {
        	staLevL2R.push(root);
        }
        while(!staLevL2R.empty() || !staLevR2L.empty())
        {
        	vector<int> vecLev;
        	if (!staLevL2R.empty())
        	{
        		while (!staLevL2R.empty())
	        	{
	        		TreeNode* curNode = staLevL2R.top();
	        		staLevL2R.pop();
	        		vecLev.push_back(curNode->val);
	        		if (curNode->left)
	        		{
	        			staLevR2L.push(curNode->left);
	        		}
	        		if (curNode->right)
	        		{
	        			staLevR2L.push(curNode->right);
	        		}
	        	}
        	}
        	else
        	{
        		while (!staLevR2L.empty())
	        	{
	        		TreeNode* curNode = staLevR2L.top();
	        		staLevR2L.pop();
	        		vecLev.push_back(curNode->val);
	        		if (curNode->right)
	        		{
	        			staLevL2R.push(curNode->right);
	        		}
	        		if (curNode->left)
	        		{
	        			staLevL2R.push(curNode->left);
	        		}
	        	}
        	}
            vecRes.push_back(vecLev);
        }
        return vecRes;
    }
};

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between). For example: Given binary tree [3,9,20,null,null,15,7], 
    3
   / \
  9  20
    /  \
   15   7
 return its zigzag level order traversal as: 
[
  [3],
  [20,9],
  [15,7]
]
 Subscribe to see which companies asked this question. Show Tags Tree Breadth-first Search Stack Show Similar Problems (M) Binary Tree Level Order Traversal
*/
