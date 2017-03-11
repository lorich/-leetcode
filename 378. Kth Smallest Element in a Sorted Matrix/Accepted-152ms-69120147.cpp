// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// 

struct Node  
{  
    int x, y;
    int val;
    Node(int _x, int _y, int _val)  
    {  
        x = _x;
        y = _y;
        val = _val;
    }  
};  
 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Using lambda to compare elements.
        auto cmp = [](Node left, Node right) { return left.val > right.val;};
        std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);
        int rows=matrix.size(), cols=matrix[0].size();
        bool* visit = new bool[rows*cols];
        memset(visit, 0, rows*cols);
        int cnt=0;
        pq.push(Node(0,0,matrix[0][0]));
        while(cnt<k-1)
        {
            auto nodeCur = pq.top();
            pq.pop();
            if (nodeCur.x < rows-1 && !visit[(nodeCur.x+1)*cols+nodeCur.y])
            {
                pq.push(Node(nodeCur.x+1, nodeCur.y, matrix[nodeCur.x+1][nodeCur.y]));
                visit[(nodeCur.x+1)*cols+nodeCur.y] = true;
            }
            if (nodeCur.y < cols-1&& !visit[(nodeCur.x)*cols+nodeCur.y+1])
            {
                pq.push(Node(nodeCur.x, nodeCur.y+1, matrix[nodeCur.x][nodeCur.y+1]));
                visit[(nodeCur.x)*cols+nodeCur.y+1] = true;
            }
            cnt++;
        }
        delete [] visit;
        return pq.top().val;
    }
};

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix. Note that it is the kth smallest element in the sorted order, not the kth distinct element. Example: 
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
 Note: You may assume k is always valid, 1 ≤ k ≤ n2. Subscribe to see which companies asked this question. Show Tags Binary Search Heap Show Similar Problems (M) Find K Pairs with Smallest Sums
*/
