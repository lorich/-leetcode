// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// 

void visitIt(char **grid, int i, int j, int numRows, int numColumns) 
{
	if (i < 0 || j < 0 || i >= numRows || j >= numColumns)
	{
		return;
	}
	grid[i][j] = '0';
	//left
	if (j > 0 && '1' == grid[i][j-1])
	{
		visitIt(grid, i, j-1, numRows, numColumns);
	}
	//right
	if (j < numColumns-1 && '1' == grid[i][j+1])
	{
		visitIt(grid, i, j+1, numRows, numColumns);
	}
	//up
	if (i > 0 && '1' == grid[i-1][j])
	{
		visitIt(grid, i-1, j, numRows, numColumns);
	}
	//down
	if (i < numRows-1 && '1' == grid[i+1][j])
	{
		visitIt(grid, i+1, j, numRows, numColumns);
	}
}

int numIslands(char **grid, int numRows, int numColumns) 
{
	int i, j, iIslands = 0;
	for (i = 0; i < numRows; ++i)
	{
		for (j = 0; j < numColumns; ++j)
		{
			if ('1' == grid[i][j])
			{
				iIslands++;
				visitIt(grid, i, j, numRows, numColumns);
			}
		}
	}   
	return iIslands;
}

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. Example 1: 11110 11010 11000 00000 Answer: 1 Example 2: 11000 11000 00100 00011 Answer: 3 Credits: Special thanks to @mithmatt for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Depth-first Search Breadth-first Search Union Find Show Similar Problems (M) Surrounded Regions (M) Walls and Gates (H) Number of Islands II (M) Number of Connected Components in an Undirected Graph
*/
