#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() and heights[i] < heights[s.top()]) {
                int index = s.top();
                s.pop();
                maxArea = max(maxArea, heights[index] * (i - 1 - (s.empty() ? -1 : s.top())));
            }
            s.push(i);
        }
        return maxArea;
    }
};