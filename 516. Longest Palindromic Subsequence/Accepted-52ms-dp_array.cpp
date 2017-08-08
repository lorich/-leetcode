#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        int longestPalindromeSubseq(const string& s) {
            int n = s.size();
            vector<vector<int>> dp(n, vector<int>(n+1, 0));
            for(size_t i=0; i<n; ++i) {
                dp[i][1] = 1;
            }
            for(size_t len=2; len<=n; ++len)
                for(size_t b=0; b<n-len+1; ++b) {
                    size_t e=b+len-1;
                    dp[b][len] = s[b]==s[e] ? 2+dp[b+1][len-2] : max(dp[b][len-1], dp[b+1][len-1]);
                }
            return dp[0][n];
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
