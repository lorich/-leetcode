#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> vRes;
    	for (int i = 0; i < nums.size();)
        {
        	if (nums[i] == -1 || nums[i] == i+1)
        	{
        		++i;
        		continue;
        	}
    		if (nums[nums[i]-1] != nums[i])
    		{
    			swap(nums[i], nums[nums[i]-1]);
    		}
    		else if(nums[i] != -1)
    		{
    			vRes.push_back(nums[i]);
    			nums[i] = -1;
    			++i;
    		}
        } 
        return vRes;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}
