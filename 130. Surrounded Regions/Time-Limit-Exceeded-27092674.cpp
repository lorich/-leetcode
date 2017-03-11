// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/
// 

typedef struct _coordinator
{
	int x, y;
	_coordinator(int i, int j) : x(i), y(j) {}
}Coord;

class Solution 
{
public:
	void BFS(vector<vector<char> >& board, int sx, int sy, int boardRowSize, int boardColSize, char target, char replace) 
	{
		queue<Coord> queCoord;
		if (target == board[sx][sy])
		{
			queCoord.push(Coord(sx,sy));
			
		}
		while(!queCoord.empty())
		{
			const Coord& curCoord = queCoord.front();
			int x=curCoord.x, y=curCoord.y;
			board[x][y] = replace;
			if (x > 0 && target == board[x-1][y])
			{
				queCoord.push(Coord(x-1,y));
			}
			if (x < boardRowSize-1 && target == board[x+1][y])
			{
				queCoord.push(Coord(x+1,y));
			}
			if (y > 0 && target == board[x][y-1])
			{
				queCoord.push(Coord(x,y-1));
			}
			if (y < boardColSize-1 && target == board[x][y+1])
			{
				queCoord.push(Coord(x,y+1));
			}
			queCoord.pop();
		}
	}
    void solve(vector<vector<char> >& board) 
    {
    	if (board.empty())
    	{
    		return;
    	}
    	//printIt(board);
    	int boardRowSize = board.size();
    	int boardColSize = board[0].size();
		for (int i = 0; i < boardRowSize; ++i)
		{
			for (int j = 0; j < boardColSize; ++j)
			{
				if ((0 == i || 0 == j || boardRowSize-1 == i || boardColSize-1 == j) && 'O' == board[i][j])
				{
					BFS(board, i, j, boardRowSize, boardColSize, 'O', 'O'-1);
				}
			}
		}
		//printIt(board);
		for (int i = 0; i < boardRowSize; ++i)
		{
			for (int j = 0; j < boardColSize; ++j)
			{
				if ('O'-1 == board[i][j])
				{
					board[i][j]++;
				}
				else
				{
					board[i][j]='X';
				}
			}
		}
		//printIt(board);
    }
};

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded region. For example, 
X X X X
X O O X
X X O X
X O X X
 After running your function, the board should be: 
X X X X
X X X X
X X X X
X O X X
 Subscribe to see which companies asked this question. Show Tags Breadth-first Search Union Find Show Similar Problems (M) Number of Islands (M) Walls and Gates
*/
