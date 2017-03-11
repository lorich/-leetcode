// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
// 

typedef struct ListNode Node; 
Node* reverseList(Node* head) {
    Node* tmpNode = NULL;
    Node* newHead = head;
    while(head && (tmpNode = head->next))
    {
    	head->next = tmpNode->next;
    	tmpNode->next = newHead;
    	newHead = tmpNode;
    }
    return newHead;
}

/*
Reverse a singly linked list. click to show more hints. Hint: A linked list can be reversed either iteratively or recursively. Could you implement both? Subscribe to see which companies asked this question. Show Tags Linked List Show Similar Problems (M) Reverse Linked List II (M) Binary Tree Upside Down (E) Palindrome Linked List
*/
