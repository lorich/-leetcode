#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 && l2) {
            if (l1->val > l2->val) {
                swap(l1, l2);
            }
            ListNode* l1c = l1;
            while(l2){
                while(l1c->next && l2->val > l1c->next->val){
                    l1c = l1c -> next;
                }
                if (NULL == l1c->next) {
                    l1c -> next = l2;
                    return l1;
                } else
                {
                    ListNode * l2n = l2->next;
                    l2 -> next = l1c -> next;
                    l1c -> next = l2;
                    l1c = l2;
                    l2 = l2n;
                }
            }
            return l1;   
        } else if (l1)
        {
            return l1;
        } else
        {
            return l2;
        }
    }
};