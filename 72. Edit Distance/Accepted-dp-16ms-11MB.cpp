#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();

        vector<vector<int>> dp(word1.size());
        for (int i = 0; i < dp.size(); ++i) {
            dp[i].resize(word2.size());
        }
        for (int i = 0; i < word2.size(); ++i) {
            if(word1[0] == word2[i]) {
                dp[0][i] = i;
            } else if(i != 0) {
                dp[0][i] = dp[0][i-1] + 1;
            }  else {
                dp[0][i] = 1;
            }
        }
        for (int i = 0; i < word1.size(); ++i) {
            if(word2[0] == word1[i]) {
                dp[i][0] = i;
            } else if (i != 0) {
                dp[i][0] = dp[i-1][0] + 1;
            } else {
                dp[i][0] = 1;
            }
        }
        for(int i = 1; i < word1.size(); ++i)
            for(int j = 1; j < word2.size(); ++j) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1]+1, dp[i-1][j]+1));
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        return dp[word1.size()-1][word2.size()-1];
    }
};

int main(){
    Solution so;
    cout << so.minDistance("horse", "rosse") << endl;
    return 0;
}