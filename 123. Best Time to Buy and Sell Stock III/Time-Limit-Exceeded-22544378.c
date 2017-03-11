// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// 

int maxProfitOneTrans(int prices[], int start, int end){
    int minPriceSofar = prices[start], maxProfitSofar = 0;
	int i;
	for(i=start; i<end; ++i)
	{
		if(prices[i] < minPriceSofar) minPriceSofar = prices[i];
		if(prices[i] - minPriceSofar > maxProfitSofar) maxProfitSofar = prices[i] - minPriceSofar;
	}
	return maxProfitSofar;
}

int maxProfit(int prices[], int n){
	int maxProfitSofar = 0, tempMax = 0;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (i==n-1 || i==0 || (prices[i]-prices[i-1])*(prices[i]-prices[i+1])>=0)
		{
			tempMax = maxProfitOneTrans(prices, 0, i) + maxProfitOneTrans(prices, i, n);
			if (tempMax > maxProfitSofar)
			{
				maxProfitSofar = tempMax;
			}
		}
	}
    return maxProfitSofar;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete at most two transactions. Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming Show Similar Problems (E) Best Time to Buy and Sell Stock (E) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock IV
*/
