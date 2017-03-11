// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// 

struct Rect {
    int iHeight, iWidth;
    int iMaxHeight, iMaxWidth;
    Rect() : iHeight(0), iWidth(0), iMaxHeight(0), iMaxWidth(0) {}
};


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int maxArea = 0;
        if (matrix.empty())
        {
            return maxArea;
        }
        int hei = matrix.size(), wid = matrix[0].size();
    	vector<vector<Rect*> > vecRect;
    	for (size_t i = 0; i <= hei; ++i)
    	{
            vector<Rect*> vecLine;
            for(size_t k=0; k <= wid; k++)
            {
                vecLine.push_back(new Rect());
            }
            vecRect.push_back(vecLine);
    		for (size_t j = 0; j <= wid; ++j)
    		{
                if (i > 0 && j > 0 && matrix[i-1][j-1] == '1')
                {
                    vecRect[i][j]->iMaxHeight = vecRect[i-1][j]->iMaxHeight+1;
                    vecRect[i][j]->iMaxWidth = vecRect[i][j-1]->iMaxWidth+1;
                    vecRect[i][j]->iHeight = min(vecRect[i][j]->iMaxHeight, vecRect[i-1][j-1]->iHeight+1);
                    vecRect[i][j]->iWidth = min(vecRect[i][j]->iMaxWidth, vecRect[i-1][j-1]->iWidth+1);
                    int curArea = vecRect[i][j]->iHeight * vecRect[i][j]->iWidth;
                    if(curArea < vecRect[i][j]->iMaxHeight)
                    {
                        vecRect[i][j]->iHeight = vecRect[i][j]->iMaxHeight;
                        vecRect[i][j]->iWidth = 1;
                        curArea = vecRect[i][j]->iMaxHeight;
                    }
                    if (curArea < vecRect[i][j]->iMaxWidth)
                    {
                        vecRect[i][j]->iHeight = 1;
                        vecRect[i][j]->iWidth = vecRect[i][j]->iMaxWidth;
                        curArea = vecRect[i][j]->iMaxWidth;
                    }
                    maxArea = max(maxArea, curArea);
                }
    		}
    	}
        return maxArea;
    }
};

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. For example, given the following matrix: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
 Return 6. Subscribe to see which companies asked this question. Show Tags Array Hash Table Stack Dynamic Programming Show Similar Problems (H) Largest Rectangle in Histogram (M) Maximal Square
*/
