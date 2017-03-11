// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/
// 

class Stack {
public:
    queue<int> m_stack;
    queue<int> m_queue;
    void reverse(queue<int>& queIn)
    {
        if (!queIn.empty())
        {
            int front = queIn.front();
            queIn.pop();
            reverse(queIn);
            queIn.push(front);
        }
    }
    // Push element x onto stack.
    void push(int x) 
    {
        m_queue.push(x);
        m_stack = m_queue;
        reverse(m_stack);
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        if (m_stack.empty())
        {
            return;
        }
        m_stack.pop();
        m_queue = m_stack;
        reverse(m_queue);
    }

    // Get the top element.
    int top() 
    {
        if (m_stack.empty())
        {
            return -1;
        }
        return m_stack.front();
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return m_stack.empty();
    }
};

/*
Implement the following operations of a stack using queues. push(x) -- Push element x onto stack. pop() -- Removes the element on top of the stack. top() -- Get the top element. empty() -- Return whether the stack is empty. Notes: You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid. Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue. You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack). Credits: Special thanks to @jianchao.li.fighter for adding this problem and all test cases. Subscribe to see which companies asked this question. Show Tags Stack Design Show Similar Problems (E) Implement Queue using Stacks
*/
