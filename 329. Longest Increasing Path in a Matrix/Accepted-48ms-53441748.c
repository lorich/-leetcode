// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// 

#define max(a,b) ((a)>(b)?(a):(b))

int lip(int m, int n, int **matrix, int matrixRowSize, int matrixColSize, int** lipMatrix)
{
	// borderline
	if (m < 0 || n < 0 || m >= matrixRowSize || n >= matrixColSize)
	{
		return 0;
	}
	// Memorization
	if (0 != lipMatrix[m][n])
	{
		return lipMatrix[m][n];
	}
	lipMatrix[m][n] = 1;
	// up
	if (m > 0 && matrix[m][n] < matrix[m-1][n])
	{
		lipMatrix[m][n] = max(lipMatrix[m][n], lip(m-1, n, matrix, matrixRowSize, matrixColSize, lipMatrix)+1);
	}
	// down
	if (m < matrixRowSize-1 && matrix[m][n] < matrix[m+1][n])
	{
		lipMatrix[m][n] = max(lipMatrix[m][n], lip(m+1, n, matrix, matrixRowSize, matrixColSize, lipMatrix)+1);
	}
	//left
	if (n > 0 && matrix[m][n] < matrix[m][n-1])
	{
		lipMatrix[m][n] = max(lipMatrix[m][n], lip(m, n-1, matrix, matrixRowSize, matrixColSize, lipMatrix)+1);
	}
	// right
	if (n < matrixColSize-1 && matrix[m][n] < matrix[m][n+1])
	{
		lipMatrix[m][n] = max(lipMatrix[m][n], lip(m, n+1, matrix, matrixRowSize, matrixColSize, lipMatrix)+1);
	}
	return lipMatrix[m][n];
}

int longestIncreasingPath(int **matrix, int matrixRowSize, int matrixColSize) 
{
	int ** lipMatrix = (int**)malloc(matrixRowSize * sizeof(int*));
	for (int i = 0; i < matrixRowSize; ++i)
	{
		lipMatrix[i] = (int*)malloc(matrixColSize * sizeof(int));
		memset(lipMatrix[i], 0, matrixColSize * sizeof(int));
	}

	int maxLip = 0;
	for (int i = 0; i < matrixRowSize; ++i)
	{
		for (int j = 0; j < matrixColSize; ++j)
		{
			maxLip = max(maxLip, lip(i, j, matrix, matrixRowSize, matrixColSize, lipMatrix));
		}
	}

	for (int i = 0; i < matrixRowSize; ++i)
	{
		free(lipMatrix[i]);
		lipMatrix[i] = NULL;
	}
	free(lipMatrix);
	lipMatrix = NULL;
	return maxLip;
}

/*
Given an integer matrix, find the length of the longest increasing path. From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed). Example 1: 
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
 Return 4 The longest increasing path is [1, 2, 6, 9]. Example 2: 
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
 Return 4 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed. Credits: Special thanks to @dietpepsi for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Depth-first Search Topological Sort Memoization
*/
