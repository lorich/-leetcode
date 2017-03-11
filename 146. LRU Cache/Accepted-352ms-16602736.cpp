// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// 

#include <map>

typedef struct _LINK_NODE
{
	int key;
    int value;
	_LINK_NODE* next;
	_LINK_NODE* pre;
}LINK_NODE;

class LRUCache
{
	LINK_NODE * m_listLRUCache;
	LINK_NODE * m_listTail;
	std::map<int, LINK_NODE *> m_mapLRUKey;
	int m_iCapacity;
public:
    LRUCache(int capacity) 
    {
        this->m_iCapacity = capacity;
        this->m_listLRUCache = NULL;
        this->m_listTail = NULL;
        this->m_mapLRUKey.clear();
    }
    
    int get(int key) 
    {
    	std::map<int, LINK_NODE *>::const_iterator itrFind = this->m_mapLRUKey.find(key);
    	if (itrFind == this->m_mapLRUKey.end())
    	{
    		//printf("get failed: not find key %d! capacity[%d] mapsize[%zu].\n", key, this->m_iCapacity, this->m_mapLRUKey.size());
    		return -1;
    	}
        //adjust list
        LINK_NODE * listNode = itrFind->second;
        if (this->m_listLRUCache != listNode)
        {
        	//check if tail node change
        	if (listNode->next == NULL)
        	{
        		this->m_listTail = listNode->pre;
        	}
        	//not head node
        	listNode->pre->next = listNode->next;
        	if (listNode->next)
        	{
        		listNode->next->pre = listNode->pre;
        	}
        	listNode->next = this->m_listLRUCache;
        	listNode->pre = NULL;
        	this->m_listLRUCache->pre = listNode;
        	this->m_listLRUCache = listNode;
        }
        return listNode->value;
    }
    
    void set(int key, int value) 
    {
        std::map<int, LINK_NODE *>::const_iterator itrFind = this->m_mapLRUKey.find(key);
    	if (itrFind == this->m_mapLRUKey.end())
    	{
    		//printf("set: not find key %d! capacity[%d] mapsize[%zu].\n", key, this->m_iCapacity, this->m_mapLRUKey.size());
    		if (this->m_mapLRUKey.empty())
    		{
    			LINK_NODE * listHead = new LINK_NODE;
    			listHead->key = key;
    			listHead->value = value;
    			listHead->next = NULL;
    			listHead->pre = NULL;
    			this->m_listLRUCache = listHead;
    			this->m_listTail = listHead;
    			this->m_mapLRUKey[key] = listHead;
    		}
    		else if(this->m_mapLRUKey.size() < this->m_iCapacity)
    		{
    			//new node
    			LINK_NODE* listNewHead = new LINK_NODE;
    			listNewHead->key = key;
    			listNewHead->value = value;
    			listNewHead->pre = NULL;
    			listNewHead->next = this->m_listLRUCache;
    			this->m_listLRUCache->pre = listNewHead;
    			this->m_listLRUCache = listNewHead;
    			this->m_mapLRUKey[key] = listNewHead;
    		}
    		else if (this->m_mapLRUKey.size() == this->m_iCapacity)
    		{
    			//cache full
    			this->m_mapLRUKey.erase(this->m_listTail->key);
    			//adjust tail node
    			LINK_NODE* listNewHead = this->m_listTail;
    			listNewHead->key = key;
    			listNewHead->value = value;
    			if (this->m_iCapacity != 1)
    			{
    				this->m_listTail = this->m_listTail->pre;
    				listNewHead->pre->next = NULL;
	    			listNewHead->pre = NULL;
	    			listNewHead->next = this->m_listLRUCache;
	    			this->m_listLRUCache->pre = listNewHead;
	    			this->m_listLRUCache = listNewHead;
    			}
    			this->m_mapLRUKey[key] = listNewHead;
    		}
    		else 
    		{
    			//printf("Cache error! capacity[%d] mapsize[%zu].\n", this->m_iCapacity, this->m_mapLRUKey.size());
    			return;
    		}
    	}
    	else
    	{
	        //adjust list
	        LINK_NODE * listNode = itrFind->second;
	        listNode->value = value;
	        if (this->m_listLRUCache != listNode)
	        {
	        	//check if tail node change
	        	if (listNode->next == NULL)
	        	{
	        		this->m_listTail = listNode->pre;
	        	}
	        	//not head node
	        	listNode->pre->next = listNode->next;
	        	if (listNode->next)
	        	{
	        		listNode->next->pre = listNode->pre;
	        	}
	        	listNode->next = this->m_listLRUCache;
	        	listNode->pre = NULL;
	        	this->m_listLRUCache->pre = listNode;
	        	this->m_listLRUCache = listNode;
	        }
    	}
    }
};

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put. get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1. put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. Follow up: Could you do both operations in O(1) time complexity? Example: 
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 Subscribe to see which companies asked this question. Show Tags Design Show Similar Problems (H) LFU Cache
*/
