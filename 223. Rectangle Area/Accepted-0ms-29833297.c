// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/
// 

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int areaSum = (D-B)*(C-A)+(H-F)*(G-E);
	int A1=max(A, E), B1=max(B, F), C1=min(C, G), D1=min(D, H);
	if (A1 >= C1 || B1 >= D1)
	{
		return areaSum;
	}
	return areaSum-(C1-A1)*(D1-B1);
}

/*
Find the total area covered by two rectilinear rectangles in a 2D plane. Each rectangle is defined by its bottom left corner and top right corner as shown in the figure. Assume that the total area is never beyond the maximum possible value of int. Credits: Special thanks to @mithmatt for adding this problem, creating the above image and all test cases. Subscribe to see which companies asked this question. Show Tags Math
*/
