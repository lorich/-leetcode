#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* pRes = nullptr;
        ListNode* pCur = pRes;
        while (1) {
            int minIndex = -1;
            int minValue = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < minValue) {
                    minValue = lists[i]->val;
                    minIndex = i;
                }
            }
            if (minIndex < 0) {
                break;
            } else {
                ListNode* pTemp = new ListNode(minValue);
                if (pCur == nullptr) {
                    pRes = pCur = pTemp;
                } else {
                    pCur->next = pTemp;
                    pCur = pTemp;
                }
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        return pRes;
    }
};