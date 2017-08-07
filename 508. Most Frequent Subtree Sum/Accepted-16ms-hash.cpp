#include <vector>
#include <unordered_map>

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
        vector<int> findFrequentTreeSum(const TreeNode* root) {
            unordered_map<int, int> hashSum;
            int maxCount = 0;
            countSum(root, hashSum, maxCount);
            vector<int> res;
            for(const auto& itr:hashSum){
                if(itr.second == maxCount) 
                    res.push_back(itr.first);
            }
            return res;
        }

        int countSum(const TreeNode* root, unordered_map<int, int>& hashSum, int& maxCount){
            if(NULL == root) return 0;
            int sum = root->val + countSum(root->left, hashSum, maxCount) + countSum(root->right, hashSum, maxCount);
            ++hashSum[sum];
            maxCount = max(hashSum[sum], maxCount);
            return sum;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
