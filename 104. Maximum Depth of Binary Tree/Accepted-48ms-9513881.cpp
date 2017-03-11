// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
        {
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRig = maxDepth(root->right);
        return maxLeft > maxRig ? maxLeft + 1 : maxRig + 1;
    }
};

/*
Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) Balanced Binary Tree (E) Minimum Depth of Binary Tree
*/
