#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
		vector<int> vecNumEndWithChar(26, 0);
		int iRes = 0;
		size_t tempLen=0;
		for(size_t i=0; i < p.size(); ++i)
		{
			int iCurChar = p[i] - 'a';
			if (i > 0 && iCurChar != (p[i-1] - 'a' + 1) % 26) tempLen = 0;
			if (++tempLen > vecNumEndWithChar[iCurChar])
			{
				iRes += tempLen - vecNumEndWithChar[iCurChar];
				vecNumEndWithChar[iCurChar] = tempLen;
			}
		}
		return iRes;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}