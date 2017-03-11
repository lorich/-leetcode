// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/
// 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head)
        {
            return head;
        }
        ListNode* pCo = head;
        ListNode* pCe = head->next; 
        while(pCo && pCe && pCe->next)
        {
            //move pce->next to pco->next
            ListNode* pCen = pCe->next;
            pCe->next = pCen->next;
            pCen->next = pCo->next;
            pCo->next = pCen;

            // move forward
            pCe = pCe->next;
            pCo = pCo->next;
        }
        return head;
    }
};

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes. You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity. Example: Given 1->2->3->4->5->NULL, return 1->3->5->2->4->NULL. Note: The relative order inside both the even and odd groups should remain as it was in the input. The first node is considered odd, the second node even and so on ... Credits: Special thanks to @DjangoUnchained for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Linked List
*/
