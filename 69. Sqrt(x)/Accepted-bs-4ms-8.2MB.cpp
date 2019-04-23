#include <iostream>

using namespace std;

class Solution {
public:
    int binSearch(int x, int low, int high)
    {
        int middle = (low + high) >> 1;
        if (middle <= x/middle and (middle + 1) > x/(middle+1))
            return middle;
        if (middle > x/middle)
            return binSearch(x, low, middle);
        else
            return binSearch(x, middle + 1, high);
    }
    int mySqrt(int x)
    {
        if(0 == x || 1 == x) return x;
        return binSearch(x, 0, x);
    }
};