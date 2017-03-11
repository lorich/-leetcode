// 143. Reorder List
// https://leetcode.com/problems/reorder-list/
// 

typedef struct ListNode sListNode;
sListNode *reverseList(sListNode *head)
{
	sListNode *headPre = NULL, *headPost = NULL;
	while(head)
	{
		headPost = head->next;
		head->next = headPre;
		headPre = head;
		head = headPost;
	}
	return headPre;
}

void mergeList(sListNode* head1, sListNode* head2)
{
	if (NULL == head1 || NULL == head2)
	{
		return;
	}
	sListNode* head2Post = NULL;
	while(head1 && head2)
	{
		if (NULL == head1->next)
		{
			head1->next = head2;
			break;
		}
		head2Post = head2->next;
		head2->next = head1->next;
		head1->next = head2;
		head1 = head2->next;
		head2 = head2Post;
	}
}

void reorderList(sListNode *head) {
	if (NULL == head || NULL == head->next)
	{
		return;
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
	mergeList(head, reverseList(slow));
}

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… You must do this in-place without altering the nodes' values. For example, Given {1,2,3,4}, reorder it to {1,4,2,3}. Subscribe to see which companies asked this question. Show Tags Linked List
*/
