// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
// 

typedef struct ListNode sListNode;
sListNode* insertIt(sListNode* head, sListNode* toInsert)
{
	if (toInsert->val < head->val)
	{
		toInsert->next = head;
		return toInsert;
	}
	sListNode* pre = head;
	sListNode* cur = head->next;
	while(cur && toInsert->val > cur->val)
	{
		pre = cur;
		cur = cur->next;
	}
	toInsert->next = cur;
	pre->next = toInsert;
	return head;
}
sListNode* insertionSortList(sListNode *head) 
{
	if (NULL == head)
	{
		return head;
	}
	sListNode* pre = head;
	sListNode* cur = head->next;
	while(cur)
	{
		if (cur->val >= pre->val)
		{
			pre = cur;
			cur = cur->next;
			continue;
		}
		else
		{
			pre->next = cur->next;
			head = insertIt(head, cur);
			cur = pre->next;
		}
	}
	return head;
}

/*
Sort a linked list using insertion sort. Subscribe to see which companies asked this question. Show Tags Linked List Sort Show Similar Problems (M) Sort List
*/
