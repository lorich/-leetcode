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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!(l1 and l2)) {
            return l1 ? l1 : l2;
        }
        ListNode* lRes = NULL;
        ListNode* lResTail = NULL;
        while(l1 and l2) {
            ListNode* lCur = NULL;
            if(l1->val < l2->val) {
                lCur = l1;
                l1 = l1->next;
            } else {
                lCur = l2;
                l2 = l2->next;
            }
            if(lResTail) {
                lResTail->next = lCur;
                lResTail = lCur;
            } else {
                lRes = lResTail = lCur;
            }
        }
        if(l1) {
            lResTail->next = l1;
        } 
        if(l2) {
            lResTail->next = l2;
        }
        return lRes;
    }
};