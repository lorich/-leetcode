// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
// 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * l3 = NULL;
        ListNode * l3tail = l3;
        int cur = 0, tonext = 0;
        while(l1 || l2)
        {
        	cur = tonext;
        	cur += l1 ? l1->val : 0;
        	cur += l2 ? l2->val : 0;
        	tonext = cur / 10;
        	cur = cur % 10;
        	ListNode * curNode = new ListNode(cur);
        	if (l3 == NULL)
        	{
        		l3 = curNode;
        	}
        	else
        	{
        		l3tail -> next = curNode;
        	}
        	l3tail = curNode;
        	l1 && (l1 = l1->next);
        	l2 && (l2 = l2->next);
        }
        if(tonext)
        {
        	ListNode * curNode = new ListNode(tonext);
        	l3tail -> next = curNode;
        }
        return l3;
    }
};

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself. Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8 Subscribe to see which companies asked this question. Show Tags Linked List Math Show Similar Problems (M) Multiply Strings (E) Add Binary (E) Sum of Two Integers (E) Add Strings (M) Add Two Numbers II
*/
