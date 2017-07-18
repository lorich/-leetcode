#include <vector>

using namespace std;


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> a(32,0);
        for(auto n: nums)
        {
        	int i=0;
        	while(n>0)
        	{
        	    a[i++] += n & 1;
        		n >>= 1;	
        	}
        }
        int res = 0, s= nums.size();
        for (auto n:a)
        {
        	res += n*(s-n);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}