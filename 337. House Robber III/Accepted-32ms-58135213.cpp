// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/
// 

class Solution {
private:
	unordered_map<TreeNode*, int> mapResCache;
public:
    int rob(TreeNode* root) {
		if (NULL == root)
		{
			this->mapResCache[root] = 0;
			return 0;
		}        
		if (this->mapResCache.find(root) != this->mapResCache.end())
		{
			return this->mapResCache[root];
		}
		int planA = 0;
		int planB = root->val;
		if (root->left)
		{
			planA += this->rob(root->left);
			planB += this->rob(root->left->left) + this->rob(root->left->right);
		}
		if (root->right)
		{
			planA += this->rob(root->right);
			planB += this->rob(root->right->left) + this->rob(root->right->right);	
		}
		this->mapResCache[root] = max(planA, planB);
		return this->mapResCache[root];
    }
};

/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night. Determine the maximum amount of money the thief can rob tonight without alerting the police. Example 1: 
     3
    / \
   2   3
    \   \ 
     3   1
 Maximum amount of money the thief can rob = 3 + 3 + 1 = 7. Example 2: 
     3
    / \
   4   5
  / \   \ 
 1   3   1
 Maximum amount of money the thief can rob = 4 + 5 = 9. Credits: Special thanks to @dietpepsi for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Tree Depth-first Search Show Similar Problems (E) House Robber (M) House Robber II
*/
