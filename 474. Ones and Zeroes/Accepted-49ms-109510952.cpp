class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> res(m+1, vector<int>(n+1, 0));
		int zeros, ones;
		for(const auto& s:strs)
		{
			zeros=ones=0;
			for(auto c:s)
			{
				c == '0' ? ++zeros : ++ones;
			}
			for (int i = m; i >= zeros; --i)
			{
				for (int j = n; j >= ones; --j)
				{
					res[i][j] = max(res[i][j], res[i-zeros][j-ones]+1);
				}
			}
		}   
		return res[m][n];     
    }
};

