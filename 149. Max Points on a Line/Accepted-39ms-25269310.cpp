// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/
// 

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
    	size_t nPoints = points.size();
    	int maxNum = 0, dublicate = 0;
    	unordered_map<double, int> umapSlope;
    	for (size_t i = 0; i < nPoints; ++i)
    	{
    		dublicate = 0;
    		umapSlope.clear();
    		umapSlope[INT_MAX]=0;
    		for (size_t j = 0; j < nPoints; ++j)
    		{
    			if (points[i].x == points[j].x && points[i].y == points[j].y)
    			{
    				dublicate++;
    				continue;
    			}
    			double dSlope = points[i].x == points[j].x ? INT_MAX : (double)(points[i].y - points[j].y)/(double)(points[i].x - points[j].x);
    			umapSlope[dSlope]++;
    		}
    		unordered_map<double, int>::const_iterator itrSlop = umapSlope.begin();
    		for (; itrSlop != umapSlope.end(); ++itrSlop)
    		{
    			if (itrSlop->second+dublicate > maxNum)
    			{
    				maxNum = itrSlop->second+dublicate;
    			}
    		}
    	}
    	return maxNum;
    }
};

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. Subscribe to see which companies asked this question. Show Tags Hash Table Math Show Similar Problems (M) Line Reflection
*/
