// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// 

typedef struct ListNode sListNode;
sListNode* deleteDuplicates(sListNode* head) 
{
	sListNode* cur = head;
	sListNode* nex = NULL;
	while(cur && (nex=cur->next))
	{
		if (cur->val == nex->val)
		{
			cur->next = nex->next;
			free(nex);
		}
		else
		{
			cur = nex;
		}
	}   
	return head; 
}

/*
Given a sorted linked list, delete all duplicates such that each element appear only once. For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3. Subscribe to see which companies asked this question. Show Tags Linked List
*/
