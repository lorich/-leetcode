#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        static string ms;
        if (ms.empty())
        {
            ms = "122";
            int i = 2;
            while(ms.size() < 100000)
            {
                ms += string(ms[i++]-'0', ms.back()^3);
            }
        }
        return std::count(ms.begin(), ms.begin()+n, '1');
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}