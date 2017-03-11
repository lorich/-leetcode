// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/
// 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head == NULL)
        {
        	return head;
        }
        RandomListNode * pListCur = head;
        RandomListNode * pNewListCur = NULL;
        while(pListCur)
        {
        	pNewListCur = new RandomListNode(pListCur->label);
         	pNewListCur->next = pListCur->next;
         	pListCur->next = pNewListCur;
        	pListCur = pNewListCur->next;
        }
        RandomListNode * newHead = head->next;
        pListCur = head;
        while(pListCur)
        {
        	pListCur->next->random = pListCur->random ? pListCur->random->next : NULL;
        	pListCur = pListCur->next->next;
        }
        pListCur = head;
        while(pListCur)
        {
        	pNewListCur = pListCur->next;
        	pListCur->next = pNewListCur->next;
        	pListCur = pListCur->next;
        	pNewListCur->next = pListCur ? pListCur->next : NULL;
        }
        return newHead;
    }
};

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. Return a deep copy of the list. Subscribe to see which companies asked this question. Show Tags Hash Table Linked List Show Similar Problems (M) Clone Graph
*/
