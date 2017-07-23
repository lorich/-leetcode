#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> window(nums.begin(), nums.begin() + k);
		auto mid = next(window.begin(), k / 2);
		vector<double> medians;
		for (int i=k; ; i++) {

			// Push the current median.
			medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

			// If all done, return.
			if (i == nums.size())
				return medians;
			window.insert(nums[i]);

			//keep mid pointing to "index" k/2
			{
				// Insert nums[i].
				if (nums[i] < *mid)	//mid pointing to k/2+1
					mid--;

				// Erase nums[i-k].
				if (nums[i-k] <= *mid)	//value to be erased not on the right of mid, which will make mid pointing to k/2-1 or mid itself be erased
					mid++;
			}
			window.erase(window.lower_bound(nums[i-k]));
		}
	}
};

int main()
{
	vector<int> input = {3,5,1,2};
	Solution so;
	so.medianSlidingWindow(input, 3);
	return 0;
}

