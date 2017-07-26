class Solution {
public:
	void dfs(const vector<int>& nums, int pos, vector<vector<int>>& res, vector<int>& seq){
		if (seq.size() > 1) res.push_back(seq);
		unordered_set<int> hash;
		for (int i = pos; i < nums.size(); ++i)
		{
			if ((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end())
			{
				seq.push_back(nums[i]);
				dfs(nums, i+1, res, seq);
				seq.pop_back();
				hash.insert(nums[i]);
			}
		}
	}

    vector<vector<int>> findSubsequences(const vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(nums, 0, res, seq);
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}