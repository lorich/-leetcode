// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/
// 

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;

    void bfs(BOARDTYPE &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M) return;
        if (board[row][col] != 'O') return;
        typedef pair<int,int> point;
        queue<point> que;
        que.push(point(row, col));
        board[row][col] = 'V';
        while(!que.empty())
        {
        	point temp = que.front();
        	que.pop();
        	int x=temp.first, y=temp.second;
        	//extending
			if (x!=0&&board[x-1][y]=='O')
			{
				que.push(point(x-1,y));
				board[x-1][y] = 'V';
			}
			if (x!=N-1&&board[x+1][y]=='O')
			{
				que.push(point(x+1,y));
				board[x+1][y] = 'V';
			}
			if (y!=0&&board[x][y-1]=='O')
			{
				que.push(point(x,y-1));
				board[x][y-1] = 'V';
			}
			if (y!=M-1&&board[x][y+1]=='O')
			{
				que.push(point(x,y+1));
				board[x][y+1] = 'V';
			}
        }
    }

    void solve(BOARDTYPE &board) {
        if (board.empty() || board[0].empty()) 
        	return;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    bfs(board, i, j);
        //printIt(board);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
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
