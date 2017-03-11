// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/
// 

class RandomizedSet {
private:
    vector<int> vecData;
    unordered_map<int, size_t> mapData;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapData.find(val) != mapData.end())
        {
            return false;
        }
        vecData.push_back(val);
        mapData[val] = vecData.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapData.find(val) == mapData.end())
        {
            return false;
        }
        if (mapData[val] != vecData.size()-1)
        {
            vecData[mapData[val]] = vecData.back();
            mapData[vecData.back()] = mapData[val];
        }
        vecData.pop_back();
        mapData.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vecData.empty()) return -1;
        return vecData[rand()%vecData.size()]; 
    }
};

/*
Design a data structure that supports all following operations in average O(1) time. insert(val): Inserts an item val to the set if not already present. remove(val): Removes an item val from the set if present. getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned. Example: 
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
 Subscribe to see which companies asked this question. Show Tags Array Hash Table Design Show Similar Problems (H) Insert Delete GetRandom O(1) - Duplicates allowed
*/
