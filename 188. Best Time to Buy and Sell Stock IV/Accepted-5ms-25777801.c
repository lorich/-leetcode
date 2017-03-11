// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// 

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int maxProfitWithNoLimit(int prices[], int n)
{
    int profit = 0, i;
	for(i=1; i<n; ++i)
	{
		if(prices[i] - prices[i-1] > 0)
		{
			profit += prices[i] - prices[i-1];
		}
	}
    return profit;
}
int maxProfit(int k, int prices[], int n) 
{
	if (0 == k || 0 == n)
	{
		return 0;
	}
	if (k >= n-1)
	{
		return maxProfitWithNoLimit(prices, n);
	}
	int * global = (int*)malloc((k+1)*sizeof(int));
	int * local = (int*)malloc((k+1)*sizeof(int));
	memset(global, 0, (k+1)*sizeof(int));
	memset(local, 0, (k+1)*sizeof(int));
	int i, j;
	for (i = 1; i < n; ++i)
	{
		int diff = prices[i] - prices[i-1];
		int times = MIN(i, k);
		for (j = times; j >= 1; --j)
		{
			local[j] = MAX(local[j]+diff, global[j-1]+MAX(diff,0));
			global[j] = MAX(local[j], global[j]);
		}
	}
    return global[k];
}

/*
Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete at most k transactions. Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). Credits: Special thanks to @Freezen for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Dynamic Programming Show Similar Problems (E) Best Time to Buy and Sell Stock (E) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III
*/
