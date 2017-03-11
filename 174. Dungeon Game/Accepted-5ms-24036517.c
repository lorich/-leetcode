// 174. Dungeon Game
// https://leetcode.com/problems/dungeon-game/
// 

//动态申请二维数组
int** malloc_Array2D(int row, int col)
{
	int size = sizeof(int);
	int point_size = sizeof(int*);
	//先申请内存，其中point_size * row表示存放row个行指针
	int **arr = (int **) malloc(point_size * row + size * row * col);
	if (arr != NULL)
	{	
		memset(arr, 0, point_size * row + size * row * col);
		int *head = (int*)((int)arr + point_size * row);
		while (row--)
			arr[row] = (int*)((int)head + row * col * size);
	}
	return (int**)arr;
}

int calculateMinimumHP(int **dungeon, int m, int n) 
{
    int iCurSum = m+n-2;
    int i, j;
    int ** tempRes = malloc_Array2D(m, n);
    while(iCurSum >= 0)
    {
    	for (i = 0; i < m; ++i)
    	{
    		j=iCurSum-i;
    		if (j >=0 && j < n)
    		{
    			int rightValid = j < n-1;
    			int downValid = i < m-1;
    			if (!rightValid && !downValid)
    			{
    				tempRes[i][j] = 1 - dungeon[i][j] > 1 ? 1 - dungeon[i][j] : 1;
    			}
    			else if (rightValid && downValid)
    			{
    				int minOne = tempRes[i+1][j] < tempRes[i][j+1] ? tempRes[i+1][j] : tempRes[i][j+1];
    				tempRes[i][j] = minOne - dungeon[i][j] > 1 ? minOne - dungeon[i][j] : 1;
    			}
    			else if (rightValid)
    			{
    				tempRes[i][j] = tempRes[i][j+1] - dungeon[i][j] > 1 ? tempRes[i][j+1] - dungeon[i][j] : 1;
    			}
    			else
    			{
    				tempRes[i][j] = tempRes[i+1][j] - dungeon[i][j] > 1 ? tempRes[i+1][j] - dungeon[i][j] : 1;
    			}
    		}
    	}
    	iCurSum--;
    }
    return tempRes[0][0];
}

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess. The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately. Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers). In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step. Write a function to determine the knight's minimum initial health so that he is able to rescue the princess. For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN. -2 (K) -3 3 -5 -10 1 10 30 -5 (P) Notes: The knight's health has no upper bound. Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned. Credits: Special thanks to @stellari for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Binary Search Dynamic Programming Show Similar Problems (M) Unique Paths (M) Minimum Path Sum
*/
