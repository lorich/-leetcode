// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// 

void maxProfitIndex(int prices[], int n, int maxProfit2end[], int maxProfit2start[]){
    int minPriceSofar = prices[0], maxProfitSofar = 0;
	int i;
	maxProfit2end[0] = 0;
	for(i=0; i<n; ++i)
	{
		if(prices[i] < minPriceSofar) minPriceSofar = prices[i];
		if(prices[i] - minPriceSofar > maxProfitSofar) maxProfitSofar = prices[i] - minPriceSofar;
		maxProfit2end[i+1] = maxProfitSofar;
	}
	int maxPriceSofar = prices[n-1];
	maxProfitSofar = 0;
	for (i=n-1; i>=0 ; --i)
	{
		if (prices[i] > maxPriceSofar) maxPriceSofar = prices[i];
		if (maxPriceSofar - prices[i] > maxProfitSofar) maxProfitSofar = maxPriceSofar - prices[i];
		maxProfit2start[i] = maxProfitSofar;
	}
}

int maxProfit(int prices[], int n){
	int *maxProfit2end = (int*)malloc((n+1)*sizeof(int));
	int *maxProfit2start = (int*)malloc((n+1)*sizeof(int));
	maxProfitIndex(prices, n, maxProfit2end, maxProfit2start);
	int maxProfitSofar = 0;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (maxProfit2end[i] + maxProfit2start[i] > maxProfitSofar)
		{
			maxProfitSofar = maxProfit2end[i] + maxProfit2start[i];
		}
	}
	return maxProfitSofar;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete at most two transactions. Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming Show Similar Problems (E) Best Time to Buy and Sell Stock (E) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock IV
*/
