#include <iostream>
#include <vector>
#include <stack>

using namespace std;



class Solution {
    public:
        vector<int> nextGreaterElements(const vector<int>& nums) {
            size_t n=nums.size();
            vector<int> next(n, -1);
            stack<size_t> s;
            for(size_t i=0; i < 2*n; ++i){
                int num = nums[i % n];
                while(!s.empty() and nums[s.top()] < num){
                    next[s.top()] = num;
                    s.pop();
                }
                if (i < n){
                    s.push(i);
                }
            }
            return next;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
