#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
	bool dfs(const vector<int>& nums, const int index, const int target, vector<int>& square) {
		if( index == nums.size() )
			return square[0] == square[1]  && square[1] == square[2] && square[2] == square[3];
		for(int i=0; i < 4; ++i) {
			if(nums[index] + square[i] > target) continue;
			
			// Pruning
			bool prune_flag = false;
			for(int j=i-1; j >= 0; --j ) {
				if(square[j] == square[i]) {
					prune_flag = true;
				}
			}
			if(prune_flag) continue;
			
			square[i] += nums[index];
			if(dfs(nums, index+1, target, square)) return true;
			square[i] -= nums[index];
		}
		return false;
	}
public:
	bool makesquare(vector<int>& nums) {
		// 1. check size
		if(nums.size() < 4) return false;

		// 2. check sum
		int sum = 0;
		for(const auto i : nums) sum += i;
		if(sum <= 0 || sum%4) return false;

		// 3. check max
		sort(nums.begin(), nums.end(), std::greater<int>());
		if(nums[0] > sum/4) return false;

		// 4. dfs
		vector<int> square(4, 0);
		return dfs(nums, 0, sum/4, square);
	}
};

int main()
{
	vector<int> input = {4,0,0,0};
	Solution so;
	cout << "b" << so.makesquare(input) << endl;
	return 0;
}
