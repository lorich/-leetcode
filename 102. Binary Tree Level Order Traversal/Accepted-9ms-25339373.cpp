// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// 

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > vecRes;
        queue<TreeNode*> queLev;
        if (root)
        {
        	queLev.push(root);
        }
        while(!queLev.empty())
        {
        	queLev.push(NULL);
        	vector<int> vecLev;
        	while(queLev.front())
        	{
        		TreeNode* curNode = queLev.front();
        		queLev.pop();
        		vecLev.push_back(curNode->val);
        		if (curNode->left)
        		{
        			queLev.push(curNode->left);
        		}
        		if (curNode->right)
        		{
        			queLev.push(curNode->right);
        		}
        	}
        	queLev.pop();
        	vecRes.push_back(vecLev);
        }
        return vecRes;
    }
};

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level). For example: Given binary tree [3,9,20,null,null,15,7], 
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as: 
[
  [3],
  [9,20],
  [15,7]
]
 Subscribe to see which companies asked this question. Show Tags Tree Breadth-first Search Show Similar Problems (M) Binary Tree Zigzag Level Order Traversal (E) Binary Tree Level Order Traversal II (E) Minimum Depth of Binary Tree (M) Binary Tree Vertical Order Traversal
*/
