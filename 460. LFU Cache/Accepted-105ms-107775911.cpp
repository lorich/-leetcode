#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
	int iCapacity;
	int iSize;
	int iMinFreq;
	unordered_map<int, pair<int, int>> mKVF;	//key->{value, freq}
	unordered_map<int, list<int>> mFListK;		//freq->keys
	unordered_map<int, list<int>::iterator> mKListI;	//key->iterator of list keys

public:
    LFUCache(int capacity) {
        iCapacity = capacity;
        iSize = 0;
    }
    
    int get(int key) {
        if (mKVF.find(key) == mKVF.end())
        {
        	return -1;
        }

        mFListK[mKVF[key].second].erase(mKListI[key]);
        mKVF[key].second++;
        mFListK[mKVF[key].second].push_back(key);
        mKListI[key] = --mFListK[mKVF[key].second].end();

        if (mFListK[iMinFreq].empty())
        {
        	iMinFreq++;
        }
        return mKVF[key].first;
    }
    
    void put(int key, int value) {
        if (iCapacity <= 0) return;
        if (get(key) != -1)
        {
        	mKVF[key].first = value;
        	return;
        }

        if (iSize >= iCapacity)
        {
        	mKVF.erase(mFListK[iMinFreq].front());
        	mKListI.erase(mFListK[iMinFreq].front());
        	mFListK[iMinFreq].pop_front();
        	iSize--;
        }

        mKVF[key] = {value, 1};
        mFListK[1].push_back(key);
        mKListI[key] = --mFListK[1].end();
        iMinFreq = 1;
        iSize++;
        return;
    }
};



