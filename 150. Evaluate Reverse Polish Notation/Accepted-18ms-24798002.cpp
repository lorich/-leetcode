// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// 

class Solution 
{
public:
    int evalRPN(vector<string> &vecTokens) 
    {
		stack<int> stackResult;
		size_t nSize = vecTokens.size();
		for (size_t i = 0; i < nSize; ++i)
		{
			const string& strCur = vecTokens[i];
			if ("+" == strCur || "-" == strCur || "*" == strCur || "/" == strCur)
			{
				if (stackResult.size() < 2)
				{
					return 0;
				}
				int iNum1 = stackResult.top();
				stackResult.pop();
				int iNum2 = stackResult.top();
				stackResult.pop();
				int iRes = 0;
				if ("+" == strCur)
				{
					iRes = iNum2 + iNum1;
				}
				else if ("-" == strCur)
				{
					iRes = iNum2 - iNum1;
				}
				else if ("*" == strCur)
				{
					iRes = iNum2 * iNum1;
				}
				else
				{
					iRes = iNum2 / iNum1;
				}
				stackResult.push(iRes);
			}
			else
			{
				stackResult.push(atoi(strCur.c_str()));
			}
		}
		if (stackResult.empty())
		{
			return 0;
		}
		else
		{
			return stackResult.top();
		}
    }
};

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are +, -, *, /. Each operand may be an integer or another expression. Some examples: 
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 Subscribe to see which companies asked this question. Show Tags Stack Show Similar Problems (H) Basic Calculator (H) Expression Add Operators
*/
