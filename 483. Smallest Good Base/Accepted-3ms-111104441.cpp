#include <string>
#include <cstdint>
#include <complex>

using namespace std;

class Solution {
    public:
        string smallestGoodBase(string n) {
            uint64_t tn=stoull(n);
            uint64_t x=1;
            for (int i=62;i>=1;i--) {
                if ((x<<i)<tn) {
                    uint64_t cur=mysolve(tn,i+1);
                    if (cur!=0) return to_string(cur);
                }
            }
            return "HaHa";
        }

        uint64_t mysolve(uint64_t n,int d) {
            //uint64_t right=pow((long double)n, 1.0/(d-1));
            if(d == 2) return n-1;
            uint64_t right = pow((double)n, 1.0/(d-1));
            uint64_t left=2;
            while (left<=right){
                uint64_t mid=left+(right-left)/2;
                uint64_t sum=1,cur=1;
                for (int i=1;i<=d-1;i++) {
                    cur*=mid;
                    sum+=cur;
                }
                if (sum==n) return mid;
                if (sum>n) right=mid-1;
                else left=mid+1;
            }
            return 0;
        }
};

int main(int argc, char const *argv[])
{
    Solution so;
    so.smallestGoodBase("727004545306745403");
    return 0;
}
