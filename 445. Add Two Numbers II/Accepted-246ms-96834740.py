# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        stackl1=[]
        stackl2=[]
        while l1 != None:
        	stackl1.append(l1.val)
        	l1=l1.next
        while l2 != None:
        	stackl2.append(l2.val)
        	l2=l2.next
        carry=0
        res=None
        while len(stackl2)>0 or len(stackl1)>0 or carry>0:
        	sum=carry
        	if len(stackl1)>0:
        		sum += stackl1.pop()
        	if len(stackl2)>0:
        		sum += stackl2.pop()
        	node=ListNode(sum%10)
        	node.next=res
        	res=node
        	carry=sum//10
        return res

def list2ln(listin):
	head=cur=None
	for i in listin:
		if head==None:
			head=ListNode(i)
			cur=head
		else:
			cur.next=ListNode(i)
			cur = cur.next
	return head



res=Solution().addTwoNumbers(list2ln([7,2,4,3]), list2ln([5,6,4]))
while res:
	print(res.val, end=r'->')
	res=res.next
print()
        
