#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(const vector<int>& nums, const int k) {
    size_t n = nums.size();
    if (n < 2) return false;
    if (1 == k) return true;
    vector<int> sum(nums);
    for (size_t len = 2; len <= n; ++len) {
      for (size_t i = 0; i < n - len + 1; ++i) {
        sum[i] += nums[i + len - 1];
        if ((0 == k and 0 == sum[i]) or (0 != k and 0 == sum[i] % k))
          return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  cout << so.checkSubarraySum({2, 2, 4, 8}, 5) << endl;
  return 0;
}