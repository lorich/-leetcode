// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// 

int maxProfit(int prices[], int n){
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

/*
Say you have an array for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). Subscribe to see which companies asked this question. Show Tags Array Greedy Show Similar Problems (E) Best Time to Buy and Sell Stock (H) Best Time to Buy and Sell Stock III (H) Best Time to Buy and Sell Stock IV (M) Best Time to Buy and Sell Stock with Cooldown
*/
