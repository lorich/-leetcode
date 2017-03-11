// 120. Triangle
// https://leetcode.com/problems/triangle/
// 

#define MIN(a,b) ((a)<(b)?(a):(b))
void swap(int **a, int **b)
{
	int *temp = *a;
	*a=*b;
	*b=temp;
}
int minimumTotal(int **triangle, int numRows) 
{
	if (numRows <= 0)
	{
		return 0;
	}
	int * preTotal = (int*)malloc(numRows*sizeof(int));
	int * curTotal = (int*)malloc(numRows*sizeof(int));
	preTotal[0] = triangle[0][0];
	int iRes = 0;
	for (int i = 1; i < numRows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			curTotal[j] = triangle[i][j];
			if (0 == j)
			{
				curTotal[j] += preTotal[j];
			}
			else if (i == j)
			{
				curTotal[j] += preTotal[j-1];
			}
			else
			{
				curTotal[j] += MIN(preTotal[j], preTotal[j-1]);
			}
		}
		swap(&preTotal, &curTotal);
	}
	iRes = preTotal[0];
	for (int i = 1; i < numRows; ++i)
	{
		iRes = iRes < preTotal[i] ? iRes : preTotal[i];
	}
	free(preTotal);
	free(curTotal);
	return iRes;   
}

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below. For example, given the following triangle 
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. Subscribe to see which companies asked this question. Show Tags Array Dynamic Programming
*/
