// 322. Coin Change
// https://leetcode.com/problems/coin-change/
// 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if (amount <=0 )
    	{
    		return 0;
    	}
        std::vector<int> vecNums(amount+1, INT_MAX);
        vecNums[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
        	for (int j = 0; j < coins.size(); ++j)
        	{
        		if (i>=coins[j] && vecNums[i-coins[j]] < INT_MAX)
        		{
        			vecNums[i] = min(vecNums[i], vecNums[i-coins[j]]+1);
        		}
        	}
        	//printf("%d: %d\n", i, vecNums[i]);
        }
        return vecNums[amount] == INT_MAX ? -1 : vecNums[amount];
    }
};

/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. Example 1: coins = [1, 2, 5], amount = 11 return 3 (11 = 5 + 5 + 1) Example 2: coins = [2], amount = 3 return -1. Note: You may assume that you have an infinite number of each kind of coin. Credits: Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Dynamic Programming
*/
