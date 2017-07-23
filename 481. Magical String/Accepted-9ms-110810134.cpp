#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
    	string ms = "122";
    	int i = 2;
    	while(ms.size() < n)
    	{
    		ms += string(ms[i++]-'0', ms.back()^3);
    	}
    	return std::count(ms.begin(), ms.begin()+n, '1');
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}