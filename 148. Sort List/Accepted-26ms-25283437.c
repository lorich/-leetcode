// 148. Sort List
// https://leetcode.com/problems/sort-list/
// 

typedef struct ListNode sListNode;

sListNode *Merge(sListNode* head1, sListNode* head2)
{
	sListNode* newHead;
	if (head1->val < head2->val)
	{
		newHead = head1;
		head1 = head1->next;
	}
	else
	{
		newHead = head2;
		head2 = head2->next;
	}
	sListNode* cur = newHead;
	while(head1 && head2)
	{
		if (head1->val < head2->val)
		{
			cur->next = head1;
			head1 = head1->next;
		}
		else
		{
			cur->next = head2;
			head2=head2->next;
		}
		cur = cur->next;
	}
	if (head1)
	{
		cur->next = head1;
	}
	else
	{
		cur->next = head2;
	}
	return newHead;
}

sListNode *MergeSort(sListNode *head) 
{
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	//fast/slow iterator to find mid node
	sListNode *fast = head, *slow = head, *slowPre = head;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slowPre = slow;
		slow = slow->next;
	}
	slowPre->next = NULL;
	return Merge(MergeSort(head), MergeSort(slow));
}

sListNode *sortList(sListNode *head) 
{
	return MergeSort(head);   
}

/*
Sort a linked list in O(n log n) time using constant space complexity. Subscribe to see which companies asked this question. Show Tags Linked List Sort Show Similar Problems (E) Merge Two Sorted Lists (M) Sort Colors (M) Insertion Sort List
*/
