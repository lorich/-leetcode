/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
        ListNode *res = NULL;
        while (head) {
            ListNode *tempHead = head;
            head = head->next;
            tempHead->next = res;
            res = tempHead;
        }
        return res;
    }
};