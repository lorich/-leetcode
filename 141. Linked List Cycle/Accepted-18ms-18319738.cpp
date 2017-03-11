// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p= head, *q=head;
        while(q && q->next)
        {
        	p = p->next;
        	q = q->next->next;
        	if(p == q)
        	{
        		return true;
        	}
        }
        return false;
    }
};

/*
Given a linked list, determine if it has a cycle in it. Follow up: Can you solve it without using extra space? Subscribe to see which companies asked this question. Show Tags Linked List Two Pointers Show Similar Problems (M) Linked List Cycle II
*/
