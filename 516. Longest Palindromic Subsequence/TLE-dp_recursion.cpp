#include <string>

using namespace std;

class Solution {
    public:
        int longestPalindromeSubseqDp(const string& s, int b, int e){
            if(e < b) return 0;
            int re = e;
            while(e > b and s[e] != s[b]) --e;
            return max(e == b ? 1 : longestPalindromeSubseqDp(s, b+1, e-1)+2, longestPalindromeSubseqDp(s, b+1, re));
        }
        int longestPalindromeSubseq(const string& s) {
            return longestPalindromeSubseqDp(s, 0, s.size()-1);
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
