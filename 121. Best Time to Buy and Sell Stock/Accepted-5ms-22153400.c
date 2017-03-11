// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 

int maxProfit(int prices[], int n){
    int minPriceSofar = prices[0], maxProfitSofar = 0;
	int i;
	for(i=0; i<n; ++i)
	{
		if(prices[i] < minPriceSofar) minPriceSofar = prices[i];
		if(prices[i] - minPriceSofar > maxProfitSofar) maxProfitSofar = prices[i] - minPriceSofar;
	}
	return maxProfitSofar;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i. If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. Example 1: 
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 Example 2: 
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming Show Similar Problems (E) Maximum Subarray (E) Best Time to Buy and Sell Stock II (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/
