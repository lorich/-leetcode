#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int counter=0;
        for (auto itr=S.rbegin(); itr != S.rend(); ++itr)
        {
        	if (*itr != '-')
        	{
                res.push_back(toupper(*itr));
        		if (++counter % K == 0)
        		{
        			res.push_back('-');
        		}
        	}
        }
        if(counter && counter % K == 0) res.pop_back();
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}