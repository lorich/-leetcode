class Solution {
public:
	int diffrence(const vector<int>& nums, int start, int end){
		if (end == start)
		{
			return nums[start];
		}
		return max(nums[start] - diffrence(nums, start+1, end), 
			nums[end] - diffrence(nums, start, end-1));
	}
    bool PredictTheWinner(vector<int>& nums) {
        return diffrence(nums, 0, nums.size()-1) >= 0;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}