#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
    	if(matrix.empty()) return res;
    	int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> tmp(m+n-1);
        for (int i = 0; i < m+n-1; ++i)
        {
        	int row=max(0, i+1-n), col=min(i, n-1);
        	for (; row < m && col >=0; ++row, --col)
        	{
        		tmp[i].push_back(matrix[row][col]);
        	}
        	if (i%2)
        	{
        		res.insert(res.end(), tmp[i].begin(), tmp[i].end());
        	}
        	else
        	{
        		res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());
        	}
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}