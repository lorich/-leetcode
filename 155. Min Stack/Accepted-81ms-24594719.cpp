// 155. Min Stack
// https://leetcode.com/problems/min-stack/
// 

class MinStack 
{
public:
	stack<int> sCont;
	stack<int> sMin;
	void push(int x) 
	{
		if (sMin.empty() || x <= sMin.top())
		{
			sMin.push(x);
		}
		sCont.push(x);
	}

	void pop() 
	{
		if (sMin.empty() || sCont.empty())
		{
			return;
		}
		if (sCont.top() == sMin.top())
		{
			sMin.pop();
		}
		sCont.pop();
	}

	int top() 
	{
		if (sCont.empty())
		{
			return -1;
		}
		return sCont.top();
	}

	int getMin() 
	{
		if (sMin.empty())
		{
			return -1;
		}
		return sMin.top();
	}
};

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. push(x) -- Push element x onto stack. pop() -- Removes the element on top of the stack. top() -- Get the top element. getMin() -- Retrieve the minimum element in the stack. Example: 
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 Subscribe to see which companies asked this question. Show Tags Stack Design Show Similar Problems (H) Sliding Window Maximum
*/
