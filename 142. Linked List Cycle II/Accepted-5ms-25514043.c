// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
// 

typedef struct ListNode sListNode;
sListNode *detectCycle(sListNode *head) {
    sListNode *p= head, *q=head;
    while(q && q->next)
    {
    	p = p->next;
    	q = q->next->next;
    	if(p == q)
    	{
    		p=head;
    		while(p != q)
    		{
    			p = p->next;
    			q = q->next;
    		}
    		return p;
    	}
    }
    return NULL;
}

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Note: Do not modify the linked list. Follow up: Can you solve it without using extra space? Subscribe to see which companies asked this question. Show Tags Linked List Two Pointers Show Similar Problems (E) Linked List Cycle (M) Find the Duplicate Number
*/
