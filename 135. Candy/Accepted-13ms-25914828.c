// 135. Candy
// https://leetcode.com/problems/candy/
// 

int candy(int ratings[], int n) 
{
	if( 0 == n)
	{
		return 0;
	}
	int * res = (int*)malloc(n*sizeof(int));
	int i;
	for(i=0; i < n; ++i)
	{
		res[i] = 1;
	}
	for(i=1; i < n; ++i)
	{
		if(ratings[i] > ratings[i-1]) 
		{
			res[i] = res[i-1]+1;
		}
	}
	for(i=n-1; i > 0; --i)
	{
		if(ratings[i-1] > ratings[i] && res[i-1] <= res[i]) 
		{
			res[i-1] = res[i]+1;
		}
	}
	int resCandy = 0;
	for(i=0; i < n; ++i)
	{
		resCandy += res[i];
	}
	free(res);
	return resCandy;
}

/*
There are N children standing in a line. Each child is assigned a rating value. You are giving candies to these children subjected to the following requirements: Each child must have at least one candy. Children with a higher rating get more candies than their neighbors. What is the minimum candies you must give? Subscribe to see which companies asked this question. Show Tags Greedy
*/
