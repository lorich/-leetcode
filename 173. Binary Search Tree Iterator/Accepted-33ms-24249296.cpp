// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// 

class BSTIterator {
public:
    stack<TreeNode*> stackNext;
    BSTIterator(TreeNode *root) 
    {
        pushNextPath(root);
    }

    void pushNextPath(TreeNode *root)
    {
        while (root)
        {
            stackNext.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !stackNext.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        if (!stackNext.empty())
        {
            TreeNode * pNext = stackNext.top();
            stackNext.pop();
            pushNextPath(pNext->right);
            return pNext->val;
        }
        return -1;
    }
};

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST. Calling next() will return the next smallest number in the BST. Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. Credits: Special thanks to @ts for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Tree Stack Design Show Similar Problems (M) Binary Tree Inorder Traversal (M) Flatten 2D Vector (M) Zigzag Iterator (M) Peeking Iterator (M) Inorder Successor in BST
*/
