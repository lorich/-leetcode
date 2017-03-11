// 382. Linked List Random Node
// https://leetcode.com/problems/linked-list-random-node/
// 

class Solution {
private:
    ListNode* m_pHead;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head):m_pHead(head) {
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* pHead = m_pHead;
        int iCounter=0, iRes;   //remain iRes undefined
        while(pHead)
        {
            iCounter++;
            if ((double)rand()/(double)RAND_MAX < 1.0/(double)iCounter)
            {
                iRes=pHead->val;
            }
            pHead=pHead->next;
        }
        return iRes;
    }
};

/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen. Follow up: What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? Example: 
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
 Subscribe to see which companies asked this question. Show Tags Reservoir Sampling Show Similar Problems (M) Random Pick Index
*/
