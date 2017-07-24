#include <vector>

using namespace std;


class Solution {
public:
	bool predictTheWinnerWithBounder(const vector<int>& nums, int left, int right, int sumSelf, int sumRival, bool isP1)
	{
		if (right == left)
		{
			return isP1 ? sumSelf + nums[left] >= sumRival : sumSelf + nums[left] > sumRival;
		}
		return !predictTheWinnerWithBounder(nums, left+1, right, sumRival, sumSelf+nums[left], !isP1)
		|| !predictTheWinnerWithBounder(nums, left, right-1, sumRival, sumSelf+nums[right], !isP1);
	}
    bool PredictTheWinner(vector<int>& nums) {
        return predictTheWinnerWithBounder(nums, 0, nums.size()-1, 0, 0, true);
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}