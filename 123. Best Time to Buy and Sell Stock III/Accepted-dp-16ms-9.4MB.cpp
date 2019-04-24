#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;
        const int T = 2;
        vector<int> profit(2 * T, INT_MIN);
        profit[0] = -prices[0];
        for (size_t i = 1; i < prices.size(); i++) {
            profit[0] = max(profit[0], -prices[i]);
            for (size_t j = 1; j < profit.size(); j++) {
                if (j % 2)  //卖出 
                    profit[j] = max(profit[j], profit[j - 1] + prices[i]);
                else    //买入
                    profit[j] = max(profit[j], profit[j - 1] - prices[i]);
            }
        }
        return max(0, profit[2 * T - 1]);
    }
};