#include <vector>

using namespace std;

// 45 ms
class Solution_0 {
private:
	vector<int> cacheRoute;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger)
        {
        	return true;
        }
        if ((1+maxChoosableInteger)*maxChoosableInteger >> 1 < desiredTotal)
        {
        	return false;
        }
        cacheRoute = vector<int>(1<<maxChoosableInteger, -1);
        return canIWin(0, maxChoosableInteger, desiredTotal);
    }

    bool canIWin(int bitsUsed, int maxChoosableInteger, int desiredTotal)
    {
    	if(cacheRoute[bitsUsed] != -1) return cacheRoute[bitsUsed];
    	for (int i = 1, bitChose = 1; i <= maxChoosableInteger; ++i, bitChose <<= 1)
    	{
    		// I chose i
    		if(bitsUsed & bitChose) continue;
    		if (i >= desiredTotal || !canIWin(bitsUsed|bitChose, maxChoosableInteger, desiredTotal - i))
    		{
    			cacheRoute[bitsUsed] = true;
    			return true;
    		}
    	}
    	cacheRoute[bitsUsed] = false;
    	return false;
   }
}; 

// 22 ms
class Solution {
private:
	vector<int> cacheRoute;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger)
        {
        	return true;
        }
        if ((1+maxChoosableInteger)*maxChoosableInteger >> 1 < desiredTotal)
        {
        	return false;
        }
        cacheRoute = vector<int>(1<<maxChoosableInteger, -1);
        return canIWin(0, maxChoosableInteger, desiredTotal);
    }

    bool canIWin(int bitsUsed, int maxChoosableInteger, int desiredTotal)
    {
    	if(cacheRoute[bitsUsed] != -1) return cacheRoute[bitsUsed];
    	for (int i = maxChoosableInteger, bitChose = 1 << (maxChoosableInteger-1); i > 0; --i, bitChose >>= 1)
    	{
    		// I chose i
    		if(bitsUsed & bitChose) continue;
    		if (i >= desiredTotal || !canIWin(bitsUsed|bitChose, maxChoosableInteger, desiredTotal - i))
    		{
    			cacheRoute[bitsUsed] = true;
    			return true;
    		}
    	}
    	cacheRoute[bitsUsed] = false;
    	return false;
   }
}; 

int main(int argc, char const *argv[])
{
	return 0;
}