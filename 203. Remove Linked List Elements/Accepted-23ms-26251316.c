// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
// 

typedef struct ListNode sListNode;
sListNode* removeElements(sListNode* head, int val) 
{
	sListNode * newHead = (sListNode *)malloc(sizeof(sListNode));
	newHead->next = head;
	sListNode * curNode = newHead;
	sListNode * nextNode = NULL;
	while(curNode && curNode->next)
	{
		nextNode = curNode->next;
		if (val == nextNode->val)
		{
			curNode->next = nextNode->next;
			free(nextNode);
		}
		else
		{
			curNode = curNode->next;
		}
	}
	return newHead->next;
}


/*
Remove all elements from a linked list of integers that have value val. Example Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6 Return: 1 --> 2 --> 3 --> 4 --> 5 Credits: Special thanks to @mithmatt for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Linked List Show Similar Problems (E) Remove Element (E) Delete Node in a Linked List
*/
