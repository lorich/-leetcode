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
    TreeNode* pre(TreeNode* root)
    {
        TreeNode* res = NULL;
        if (root) {
            root = root->left;
            while (root) {
                res = root;
                root = root->right;
            }
        }
        return res;
    }

    TreeNode* post(TreeNode* root)
    {
        TreeNode* res = NULL;
        if (root) {
            root = root->right;
            while (root) {
                res = root;
                root = root->left;
            }
        }
        return res;
    }

    bool isValidBST(TreeNode* root)
    {
        if (NULL == root)
            return true;
        TreeNode* preNode = pre(root);
        TreeNode* postNode = post(root);
        if ((preNode == NULL or preNode->val < root->val) and (postNode == NULL or postNode->val > root->val)) {
            return isValidBST(root->left) and isValidBST(root->right);
        }
        return false;
    }
};