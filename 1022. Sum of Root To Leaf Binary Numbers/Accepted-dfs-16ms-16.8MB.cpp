/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int parentSum = 0) {
        if(NULL == root) return 0;
        parentSum = (parentSum << 1) + root->val;
        if(NULL == root->left && NULL == root->right) return parentSum;
        return sumRootToLeaf(root->left, parentSum) + sumRootToLeaf(root->right, parentSum);
    }
};