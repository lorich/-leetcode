#include <string>
#include <cstdint>
#include <complex>
#include <iostream>

using namespace std;

class Solution {
    public:
        string smallestGoodBase(string n) {
            uint64_t tn=stoull(n);
            uint64_t x=1;
            for (int i=62;i>=1;i--) {
                if ((x<<i)<tn) {
                    uint64_t cur=mysolve(i+1, tn);
                    if (cur!=0) return to_string(cur);
                }
            }
            return "HaHa";
        }

        //f(x)
        inline long double fx(const long double& b, const int& d, const uint64_t& n)
        {
            return (pow(b, d)-1)/(b-1)-n;
        }

        //f'(x)
        inline long double fDx(const long double& b, const int& d, const uint64_t& n)
        {
            long double bd = pow(b, d-1);
            return bd*d/(b-1)-(bd*b-1)/((b-1)*(b-1));
        }

        uint64_t mysolve(const int d, const uint64_t n) {
            if(d == 2) return n-1;
            // Newton
            long double cb =2, pb = 0;
            while((uint64_t)cb != (uint64_t)pb)
            {
                pb = cb;
                cb = cb - fx(cb, d, n)/fDx(cb, d, n);
                //printf("--%Lf %Lf %Lf\n", cb, pb, fx(cb, d, n));
            }
            //printf("%llu %d %Lf\n", (uint64_t)cb, d, abs(fx((uint64_t)cb, d, n)));
            if((uint64_t)cb>1 && abs(fx((uint64_t)cb, d, n)) < 1e-1) return cb;
            if(abs(fx((uint64_t)cb+1, d, n)) < 1e-1) return cb+1;
            return 0;
        }
};

//"470988884881403701": "686286299"
int main(int argc, char const *argv[])
{
    Solution so;
    cout << so.smallestGoodBase("470988884881403701") << endl;
    return 0;
}
