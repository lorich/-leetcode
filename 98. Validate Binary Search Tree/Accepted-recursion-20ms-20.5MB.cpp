/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal or root->val >= maxVal) return false;
        return isValid(root->left, minVal, root->val) and isValid(root->right, root->val, maxVal);
    }
};