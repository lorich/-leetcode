#include <vector>
#include <iostream>

using namespace std;


int cache[20][20];
bool cacheSet[20][20];

class Solution {
public:
	int diffrence(const vector<int>& nums, int start, int end){
		if (cacheSet[start][end])
		{
			return cache[start][end];
		}
		if (start == end)
		{
			cache[start][end] = nums[start];
		}
		else
		{
			cache[start][end] = max(nums[start] - diffrence(nums, start+1, end), nums[end] - diffrence(nums, start, end-1));
		}
		cacheSet[start][end] = true;
		return cache[start][end];
	}
    bool PredictTheWinner(vector<int>& nums) {
    	memset(cacheSet, 0, 40);
        return diffrence(nums, 0, nums.size()-1) >= 0;
    }
};

int main(int argc, char const *argv[])
{
	Solution so;
	vector<int> in = {1,2,1};
	so.PredictTheWinner(in);
	return 0;
}