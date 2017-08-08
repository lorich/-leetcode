#include <string>

using namespace std;

int cache[1000][1000];
class Solution {
    public:
        int longestPalindromeSubseqDp(const string& s, int b, int e){
            if(e < b) return 0;
            if(0 != cache[b][e]) return cache[b][e];
            int re = e;
            while(e > b and s[e] != s[b]) --e;
            cache[b][re] = max(e == b ? 1 : longestPalindromeSubseqDp(s, b+1, e-1)+2, longestPalindromeSubseqDp(s, b+1, re));
            return cache[b][re];
        }
        int longestPalindromeSubseq(const string& s) {
            memset(cache, 0, 1000*1000*sizeof(int));
            return longestPalindromeSubseqDp(s, 0, s.size()-1);
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
