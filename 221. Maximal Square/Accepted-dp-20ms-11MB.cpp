#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.empty() or matrix[0].empty())
            return 0;
        size_t m = matrix.size(), n = matrix[0].size();
        int iMaxSide = 0;
        // dp 数组 (i,j) 代表 matrix 中，以 (i,j) 为右下节点的最大正方形边长
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++) {
                if (i == 0 or j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                if (dp[i][j] > iMaxSide)
                    iMaxSide = dp[i][j];
            }
        return iMaxSide * iMaxSide;
    }
};