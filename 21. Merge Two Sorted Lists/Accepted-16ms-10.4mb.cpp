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
        ListNode *lResult = NULL;
        ListNode *lPre = NULL;
        while (l1 || l2)
        {
            ListNode *lCurrent = new ListNode(0);
            lCurrent->next = NULL;
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    lCurrent->val = l1->val;
                    l1 = l1->next;
                }
                else
                {
                    lCurrent->val = l2->val;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                lCurrent->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                lCurrent->val = l2->val;
                l2 = l2->next;
            }
            if (NULL == lResult)
            {
                lResult = lCurrent;
            }
            if (NULL != lPre)
            {
                lPre->next = lCurrent;
            }
            lPre = lCurrent;
        }
        return lResult;
    }
};