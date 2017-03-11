// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// 

typedef struct _LINK_NODE
{
	int key;
    int value;
    _LINK_NODE* pre;
	_LINK_NODE* next;
}LINK_NODE;

class LRUCache
{
public:
	LINK_NODE * m_listLRUCache;
	LINK_NODE * m_listTail;
    int m_iCacheSize;
	int m_iCapacity;
public:
    LRUCache(int capacity) 
    {
        this->m_iCapacity = capacity;
        this->m_iCacheSize = 0;
        this->m_listLRUCache = NULL;
        this->m_listTail = NULL;
    }
    
    int get(int key) 
    {
        int iRet = -1;
        LINK_NODE* listCurNode = this->m_listLRUCache;
        while(listCurNode)
        {
            if (listCurNode->key == key)
            {
                //adjust head&tail node
                if (this->m_listLRUCache != listCurNode)
                {
                    //check if tail node change
                    if (listCurNode->next == NULL)
                    {
                        this->m_listTail = listCurNode->pre;
                    }
                    //not listCurNode node
                    listCurNode->pre->next = listCurNode->next;
                    if (listCurNode->next)
                    {
                        listCurNode->next->pre = listCurNode->pre;
                    }
                    listCurNode->next = this->m_listLRUCache;
                    listCurNode->pre = NULL;
                    this->m_listLRUCache->pre = listCurNode;
                    this->m_listLRUCache = listCurNode;
                }
                iRet = listCurNode->value;
                break;
            }
            listCurNode = listCurNode->next;
        }
        return iRet;
    }
    
    void set(int key, int value) 
    {
        LINK_NODE* listCurNode = this->m_listLRUCache;
        //search the key
        while(listCurNode)
        {
            if (listCurNode->key == key)
            {
                listCurNode->value = value;
                //adjust head&tail node
                if (this->m_listLRUCache != listCurNode)
                {
                    //check if tail node change
                    if (listCurNode->next == NULL)
                    {
                        this->m_listTail = listCurNode->pre;
                    }
                    //not listCurNode node
                    listCurNode->pre->next = listCurNode->next;
                    if (listCurNode->next)
                    {
                        listCurNode->next->pre = listCurNode->pre;
                    }
                    listCurNode->next = this->m_listLRUCache;
                    listCurNode->pre = NULL;
                    this->m_listLRUCache->pre = listCurNode;
                    this->m_listLRUCache = listCurNode;
                }
                break;
            }
            listCurNode = listCurNode->next;
        }
        //not found
        if (listCurNode == NULL)
        {
            //printf("set: not find key %d! capacity[%d] mapsize[%zu].\n", key, this->m_iCapacity, this->m_mapLRUKey.size());
            if (this->m_iCacheSize == 0)
            {
                LINK_NODE * listHead = new LINK_NODE;
                listHead->key = key;
                listHead->value = value;
                listHead->next = NULL;
                listHead->pre = NULL;
                this->m_listLRUCache = listHead;
                this->m_listTail = listHead;
                this->m_iCacheSize++;
            }
            else if(this->m_iCacheSize < this->m_iCapacity)
            {
                //new node
                LINK_NODE* listNewHead = new LINK_NODE;
                listNewHead->key = key;
                listNewHead->value = value;
                listNewHead->pre = NULL;
                listNewHead->next = this->m_listLRUCache;
                this->m_listLRUCache->pre = listNewHead;
                this->m_listLRUCache = listNewHead;
                this->m_iCacheSize++;
            }
            else if (this->m_iCacheSize == this->m_iCapacity)
            {
                //cache full
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
            }
            else 
            {
                printf("Cache error! capacity[%d] mapsize[%zu].\n", this->m_iCapacity, this->m_iCacheSize);
                return;
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
