#include <vector>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void bfs(const vector<TreeNode*>& layer, vector<int>& res){
		if(layer.empty())
			return;
		vector<TreeNode*> nextLayer;
		int maxVal = INT_MIN;
		for(auto node:layer)
		{
			maxVal = max(maxVal, node->val);
			if(node->left) nextLayer.push_back(node->left);
			if(node->right) nextLayer.push_back(node->right);
		}
		res.push_back(maxVal);
		bfs(nextLayer, res);
	}
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> layer;
        if(root) layer.push_back(root);
        bfs(layer, res);
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}