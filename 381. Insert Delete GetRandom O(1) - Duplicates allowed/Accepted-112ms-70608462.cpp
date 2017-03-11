// 381. Insert Delete GetRandom O(1) - Duplicates allowed
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// 

#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

class RandomizedCollection {
private:
    vector<int> vecData;
    unordered_map<int, vector<size_t>> mapData;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vecData.push_back(val);
        mapData[val].push_back(vecData.size()-1);
        return mapData[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mapData.find(val) == mapData.end())
        {
            return false;
        }
        if (mapData[val].back() != vecData.size()-1)
        {
            vecData[mapData[val].back()] = vecData.back();
            mapData[vecData.back()].pop_back();
            mapData[vecData.back()].push_back(mapData[val].back());
        }
        mapData[val].pop_back();
        if (mapData[val].empty())
        {
            mapData.erase(val);
        }
        vecData.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        //for(auto i:vecData)cout << i << "\t";cout<<endl;
        if(vecData.empty()) return -1;
        return vecData[rand()%vecData.size()]; 
    }
};


/*
Design a data structure that supports all following operations in average O(1) time. Note: Duplicate elements are allowed. insert(val): Inserts an item val to the collection. remove(val): Removes an item val from the collection if present. getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains. Example: 
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
 Subscribe to see which companies asked this question. Show Tags Array Hash Table Design Show Similar Problems (M) Insert Delete GetRandom O(1)
*/
